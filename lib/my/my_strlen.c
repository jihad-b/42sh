/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** mstrlen
*/

#include "../../includes/my.h"

int my_strlen(char const *str)
{
    int tabl = 0;
    while (str[tabl] != '\0') {
        tabl = tabl + 1;
    }
    return (tabl);
}

int my_tablen(char **dest)
{
    int nb = 0;

    for (nb = 0; dest[nb] != NULL; nb++);
    return nb;
}