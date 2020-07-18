/*
** EPITECH PROJECT, 2019
** hexa
** File description:
** hexa
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../includes/my.h"

int printh(va_list params, char const *str, int a)
{
    if (str[a] == '%' && str[a+1] == 'x') {
        tohexa(va_arg(params, int), basex);
        a += 1;
    }
    if (str[a] == '%' && str[a+1] == 'X') {
        tohexa(va_arg(params, int), baseX);
        a += 1;
    }
    if (str[a] == '%' && str[a+1] == '#' && str[a+2] == 'x') {
        my_putstr("0x");
        tohexa(va_arg(params, int), basex);
        a += 2;
    }
    if (str[a] == '%' && str[a+1] == '#' && str[a+2] == 'X') {
        my_putstr("0X");
        tohexa(va_arg(params, int), baseX);
        a += 2;
    }
    return (a);
}

int tohexa(unsigned int number, char *base)
{
    int taille = my_strlen(base);
    char *str = malloc(sizeof(char) * ( 11 + 1 ));
    unsigned int reste = 1;
    unsigned int res = 1;
    int i = 0;

    while (res != 0) {
        res = number / taille;
        reste = number - (res * taille);
        number = res;
        str[i++] = base[reste];
    }
    str[i++] = '\0';
    my_putstr(my_revstr(str));
    return (0);
}
