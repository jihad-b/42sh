/*
** EPITECH PROJECT, 2020
** de
** File description:
** de
*/

#include "my.h"

static char **change_arg(char **arg, int nb, shell_s *shell)
{
    int b = 0;
    char **dest = malloc(sizeof(char *) * my_tablen(arg) + 1);
    int out_fd = open(arg[nb + 1], O_RDONLY);

    shell->fd = out_fd;
    shell->check = 2;
    for (int a = 0, b = 0; arg[a] != NULL; a++) {
        if (nb == a)
            a += 1;
        else {
            dest[b] = malloc(sizeof(char) * my_strlen(arg[a]) + 1);
            dest[b] = my_strcpy(dest[b], arg[a]);
            b++;
        }
    }
    dest[++b] = NULL;
    return dest;
}

static char **change_arg2(char **arg, int nb, shell_s *shell)
{
    int b = 0;
    char **dest = malloc(sizeof(char *) * my_tablen(arg) + 1);
    int out_fd = open(&arg[nb][1], O_RDONLY);

    shell->fd = out_fd;
    shell->check = 2;
    for (int a = 0, b = 0; arg[a] != NULL; a++) {
        if (nb != a) {
            dest[b] = malloc(sizeof(char) * my_strlen(arg[a]) + 1);
            dest[b] = my_strcpy(dest[b], arg[a]);
            b++;
        }
    }
    dest[++b] = NULL;
    return dest;
}

static void change_args(char **arg, int nb, shell_s *shell)
{
    int b = 0;
    char **dest = malloc(sizeof(char *) * my_tablen(arg) + 1);
    int out_fd = open(arg[nb + 1],  O_WRONLY | O_CREAT | O_TRUNC, 0666);

    shell->fd = out_fd;
    shell->check = 1;
    for (int a = 0, b = 0; arg[a] != NULL; a++) {
        if (nb == a)
            a += 1;
        else {
            dest[b] = malloc(sizeof(char) * my_strlen(arg[a]) + 1);
            dest[b] = my_strcpy(dest[b], arg[a]);
            b++;
        }
    }
    dest[++b] = NULL;
    shell->stock = dest;
    return;
}

static void change_args2(char **arg, int nb, shell_s *shell)
{
    int b = 0;
    char **dest = malloc(sizeof(char *) * my_tablen(arg) + 1);
    int out_fd = open(&arg[nb][1], O_WRONLY | O_CREAT | O_TRUNC, 0666);

    shell->fd = out_fd;
    shell->check = 1;
    for (int a = 0, b = 0; arg[a] != NULL; a++) {
        if (nb != a) {
            dest[b] = malloc(sizeof(char) * my_strlen(arg[a]) + 1);
            dest[b] = my_strcpy(dest[b], arg[a]);
            b++;
        }
    }
    dest[++b] = NULL;
    shell->stock = dest;
    return;
}

void find_change_arg(shell_s *shell)
{
    shell->check = 0;

    for (int a = 0; shell->stock[a] != NULL; a++)
        for (int b = 0; shell->stock[a][b] != '\0'; b++) {
            if (shell->stock[a][b] == '<' && shell->stock[a][b + 1] == '\0') {
                shell->stock = change_arg(shell->stock, a, shell);
                break;
            } else if (shell->stock[a][b] == '<' &&
            shell->stock[a][b + 1] != '\0' && shell->stock[a][b + 1] != '<') {
                shell->stock =  change_arg2(shell->stock, a, shell);
                break;
            }
            if (shell->stock[a][b] == '>' && shell->stock[a][b + 1] == '>'
            && shell->stock[a][b + 2] == '\0')
                return change_argsd(shell->stock, a, shell);
            else if (shell->stock[a][b] == '>' && shell->stock[a][b + 1] == '>'
            && shell->stock[a][b + 2] != '\0')
                return change_args2d(shell->stock, a, shell);
            if (shell->stock[a][b] == '>' && shell->stock[a][b + 1] == '\0')
                return change_args(shell->stock, a, shell);
            else if (shell->stock[a][b] == '>' &&
            shell->stock[a][b + 1] != '\0' && shell->stock[a][b + 1] != '>')
                return change_args2(shell->stock, a, shell);

        }
}
