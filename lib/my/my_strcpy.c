/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** task01
*/

#include "./../../includes/my.h"

char *my_strcpy(char *dest, char *src)
{
    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    int a = 0;

    for (;src[a] != '\0';a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return (dest);
}
