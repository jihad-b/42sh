/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** perror
*/

#include <unistd.h>

int my_strlen(char *str);

char *my_strcat(char *, char *);

void my_perror(char *str)
{
    write(2, str, my_strlen(str));
}
