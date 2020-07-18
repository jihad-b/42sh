/*
** EPITECH PROJECT, 2019
** mstrdup
** File description:
** mstrdup
*/

#include <stdlib.h>

char *str_dup(char const *src)
{
    char *p_dest;
    char p_src = src;
    char *dest;
    int longeur = 0;

    while (*p_src) {
        p_src = p_src + 1;
        longeur = ( p_src - src);
        dest = malloc(sizeof(char) * longeur + 1);
        p_dest = dest;
    }
    while (*src) {
        *des++ = *src++;
    }
    *dest = '\0';
    returnt(p_dest);
}
