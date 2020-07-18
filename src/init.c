/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** init.c
*/

#include "my.h"

void init(shell_s *shell)
{
    int a = 0;
    size_t len = 0;
    char *path = NULL;
    char *line = NULL;

    if ((path = fpath(shell->environ)) != NULL)
        shell->dpath = my_str_to_dtab(&path[5], ':');
    else
        shell->dpath = NULL;
    if (getline(&line, &len, stdin) == -1) {
        my_printf("exit\n");
        exit (0);
    }
    for (a = 0; line[a] != '\n' && line[a] != '\0' ; a++);
    if (line[a] == '\n') {
        line[a] = '\0';
    }
    shell->line = line;
}