/*
** EPITECH PROJECT, 2020
** fichier
** File description:
** fichier
*/

#include"../includes/my.h"

int exec_bin(char **stock, char **environ)
{
    struct stat s;
    pid_t cpid;

    stat(stock[0], &s);
    if (S_ISDIR(s.st_mode)) {
        my_perror(my_strcat(stock[0], ": Permission denied.\n"));
        return 0;
    }
    cpid = fork();
    if (cpid == 0){
        execve(stock[0], stock, environ);
        my_perror(my_strcat(stock[0], ": Command not found.\n"));
    } else
        check_seg();
    return 0;
}

char *find_cmd(char *line, int a, int tmp)
{
    int taille = a - tmp;
    char *dest = NULL;

    if ((dest = malloc(sizeof(char) * (taille + 1))) == NULL)
        return NULL;
    a--;
    for (int b = 0; b != taille; b++, a--)
        dest[b] = line[a];
    dest[taille] = '\0';
    return my_revstr(dest);
}

void exec_pipe1(char **f_cmd, char **t_cmd, shell_s *shell, int a)
{
    int pid = 0;

    if ((pid = pipe_fork()) == 1)
        exit(84);
    else if (pid == 0) {
        change_redirection(shell);
        if (execve(my_strcat("/usr/bin/", f_cmd[0]), f_cmd,
        shell->environ) == -1)
            exit (84);
    } else {
        change_redirection(shell);
        if (a == 0) {
            if (execve(my_strcat("/usr/bin/", f_cmd[0]), f_cmd,
            shell->environ) == -1)
                    exit (84);
        } else {
            if (execve(my_strcat("/usr/bin/", t_cmd[0]), t_cmd,
            shell->environ) == -1)
                    exit (84);
        }
    }
}