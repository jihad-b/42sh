/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** task01
*/

#include"../../includes/my.h"

char *my_strcat(char *dest, char *src)
{
    int a = 0;
    char *str = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    for (int b = 0; dest[b] != '\0'; b++, a++)
        str[a] = dest[b];
    for (int b = 0; src[b] != '\0'; b++, a++)
        str[a] = src[b];
    str[a] = '\0';
    return str;
}
