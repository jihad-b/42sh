/*
** EPITECH PROJECT, 2020
** redirection sortie 2
** File description:
** 42sh
*/

#include "my.h"

void change_argsd(char **arg, int nb, shell_s *shell)
{
    int b = 0;
    char *buffer = malloc(sizeof(char) * 2048);
    char **dest = malloc(sizeof(char *) * my_tablen(arg) + 1);
    int out_fd = open(arg[nb + 1],  O_RDWR | O_CREAT | O_TRUNC, 0666);

    read(out_fd, buffer, 2048);
    write(out_fd, buffer, my_strlen(buffer));
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
    dest[++b] = NULL, shell->stock = dest;
    return;
}

void change_args2d(char **arg, int nb, shell_s *shell)
{
    int b = 0;
    char *buffer = malloc(sizeof(char) * 2048);
    char **dest = malloc(sizeof(char *) * my_tablen(arg) + 1);
    int out_fd = open(&arg[nb][2], O_RDWR | O_CREAT | O_TRUNC, 0666);

    read(out_fd, buffer, 2048);
    write(out_fd, buffer, my_strlen(buffer));
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
