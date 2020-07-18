/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** pipe.c
*/

#include "my.h"

pid_t pipe_fork(void)
{
    int pfd[2];
    pid_t pid;

    if (pipe(pfd) < 0)
        return -1;
    if ((pid = fork()) < 0)
        return -1;
    if (pid == 0) {
        close(pfd[0]);
        dup2(pfd[1], STDOUT_FILENO);
    } else {
        close(pfd[1]);
        dup2(pfd[0], STDIN_FILENO);
    }
    return pid;
}

static int pip(char **environ, char *av, shell_s *shell)
{
    pid_t pid;
    char **f_cmd = my_str_to_dtab(find_fisrt_cmd(av), ' ');
    char **t_cmd = my_str_to_dtab(find_two_cmd(av), ' ');

    if ((pid = pipe_fork()) < 0)
        exit (84);
    change_redirection(shell);
    if (pid == 0)
        exec_pipe1(f_cmd, t_cmd, shell, 0);
    else
        if (execve(my_strcat("/usr/bin/", t_cmd[0]), t_cmd, environ) == -1)
            return 84;
    if ((pid = pipe_fork()) < 0)
        return 84;
    return 0;
}

static int pip2(char **environ, char *av, shell_s *shell)
{
    pid_t pid;
    char **f_cmd = my_str_to_dtab(find_fisrt_cmd(av), ' ');
    char **t_cmd = my_str_to_dtab(find_two_cmd(av), ' ');
    char **th_cmd = my_str_to_dtab(find_third_cmd(av), ' ');

    if ((pid = pipe_fork()) < 0)
        return 84;
    change_redirection(shell);
    if (pid == 0)
        exec_pipe1(f_cmd, t_cmd, shell, 1);
    else
        if (execve(my_strcat("/usr/bin/", th_cmd[0]), th_cmd, environ) == -1)
            return 84;
    if ((pid = pipe_fork()) < 0)
        return 84;
    return 0;
}

int check_pipe(char *str)
{
    int nb = 0;

    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '|')
            nb++;
    return nb;
}

int exec_pipe(char **environ, char *line, shell_s *shell)
{
    int pid;

    line = find_change_arg2(shell, line);
    if (check_pipe(line) == 1) {
        if ((pid = fork()) == 0)
            pip(environ, line, shell);
        else
            wait(NULL);
        kill(pid, SIGQUIT);
        return 1;
    }
    else if (check_pipe(line) == 2) {
        if ((pid = fork()) == 0)
            pip2(environ, line, shell);
        else
            wait(NULL);
        kill(pid, SIGQUIT);
        return 1;
    }
    return 0;
}
