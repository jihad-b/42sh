/*
** EPITECH PROJECT, 2020
** de
** File description:
** de
*/

#include "my.h"

void change_redirection(shell_s *shell)
{
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
}

static char *find_name_file(int b, char *line)
{
    int c = b;
    char *file = NULL;

    for (;line[c] != ' ' && line[c] != '\t' && line[c] != '\0' ; c++);
    file = malloc(sizeof(char) * (c - b + 1));
    for (int a = b; line[a] != '\0' && a != c; a++) {
        file[a - b] = line[a];
        if (a + 1 == c)
            file[a - b + 1] = '\0';
    }
    return file;
}

static char *cmd(char *line, char *file)
{
    int a = 0;
    char *lines = malloc(sizeof(char) *
    my_strlen(line) - (my_strlen(file) + 1));

    for (int c = 0; line[c] != '\0'; c++, a++) {
        if (line[c] == '>') {
            c++;
            for (;line[c] == ' ' || line[c] == '\t'; c++);
            for (;line[c] != ' ' && line[c] != '\t' && line[c] != '\0';
            c++);
        }
        lines[a] = line[c];
    }
    lines[a] = '\0';
    return lines;
}

char *find_change_arg2(shell_s *shell, char *line)
{
    char *file = NULL;

    for (int b = 0; line[b] != '\0'; b++) {
        if (line[b] == '>') {
            b++;
            for (;line[b] == ' ' || line[b] == '\t'; b++);
            file = find_name_file(b, line);
            shell->fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
            shell->check = 1;
            return cmd(line, file);
        }
    }
    return line;
}