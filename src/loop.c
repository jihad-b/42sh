/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** loop
*/

#include "../includes/my.h"
#include <sys/types.h>
#include <signal.h>

char *name(char *dest)
{
    int tmp = 0;
    int temp = 0;
    char *buffer = malloc(sizeof(char)* 10000000);
    size_t size = 10000000;
    char *get = getcwd(buffer, size);
    int sizerepo = my_strlen(get);

    for (int a = sizerepo; get[a] != '/'; tmp++, a--);
    dest = malloc(sizeof(char) * tmp + 1);
    for (int a = sizerepo - tmp + 1; get[a] != '\0'; a++, temp++)
        dest[temp] = get[a];
    return dest;
}

static void exec_cmd(shell_s *shell, char *str)
{
    int cpid = fork();

    if (cpid == 0) {
        if (shell->check == 1) {
            dup2(shell->fd, STDOUT_FILENO);
            close(shell->fd);
            shell->check = 0;
        }
        if (shell->check == 2) {
            if(dup2(shell->fd, STDIN_FILENO) < 0) {
                my_printf("Unable to duplicate file descriptor.");
                exit(84);
            }
            close(shell->fd);
            shell->check = 0;
        }
        shell->pid = cpid;
        if (execve(str, shell->stock, shell->environ) == -1)
            return;
    } else {
        wait(NULL);
        return;
    }
}

static void exec(char **dpath, char *str, char **stock, shell_s *shell)
{
    struct stat stats;

    for (int i = 0; dpath[i] != NULL; i++) {
        str = path_complet(str, dpath[i], stock[0]);
        if (stat(str, &stats) != -1)
            return exec_cmd(shell, str);
    }
    exec_bin(stock, shell->environ);
    return;
}

void loop(shell_s *shell, char *str)
{
    kill(shell->pid, SIGKILL);
    find_change_arg(shell);
    if (shell->stock != NULL && shell->stock[0] && shell->check != -1) {
        shell->stock = check_alias(shell->stock);
        if (my_strcmp(shell->stock[0], "alias") == 0) {
            alias(shell->stock);
            return;
        } else if (my_strcmp(shell->stock[0], "unalias") == 0) {
            unalias(shell->stock[1]);
            return;
        }
        if (my_strcmp(shell->stock[0], "exit") == 0) {
            exit(0);
        } else if (my_strcmp(shell->stock[0], "env") == 0)  {
            for (int a = 0; shell->environ[a] != NULL; a++)
                my_printf("%s\n", shell->environ[a]);
            return;
        }
        if (my_strcmp(shell->stock[0], "cd") == 0 && shell->dpath != NULL) {
            cd(shell->stock, shell->environ);
            return;
        } else if (my_strcmp(shell->stock[0], "setenv")== 0 ||
                my_strcmp(shell->stock[0], "unsetenv") == 0) {
            shell->environ = check_set_or_unset(shell->environ, shell->stock);
            return;
        } else
            if (shell->dpath != NULL)
                exec(shell->dpath, str, shell->stock, shell);
    }
}
