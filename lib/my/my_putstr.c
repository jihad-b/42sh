/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** task02
*/

#include "../../includes/my.h"

int my_putstr(char *str)
{
    int tabl = 0;

    while (str[tabl] != '\0'){
        my_putchar(str[tabl]);
        tabl = tabl + 1;
    }
    return (0);
}
