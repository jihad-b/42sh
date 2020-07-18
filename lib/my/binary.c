/*
** EPITECH PROJECT, 2019
** binary
** File description:
** binary
*/

#include <stdlib.h>
#include "../../includes/my.h"

int print_o_b(va_list params, char const *str, int a)
{
    if (str[a] == '%' && str[a+1] == 'o') {
        toctal(va_arg(params, int));
        a += 1;
    }
    if (str[a] == '%' && str[a+1] == '#' && str[a+2] == 'o') {
        my_putchar('0');
        toctal(va_arg(params, int));
        a += 2;
    }
    if (str[a] == '%' && str[a+1] == 'b') {
        tobinary(va_arg(params, int));
        a += 1;
    }
    return (a);
}

int tobinary(unsigned int number)
{
    unsigned int maximum = 2147483648;

    while (maximum != 0) {
        if (number >= maximum) {
            my_putchar('1');
            number = number - maximum;
        } else {
            my_putchar('0');
        }
        maximum = maximum / 2;
    }
    return (0);
}

int toctal(unsigned int number)
{
    char *str = malloc(sizeof(char) * ( 11 + 1 ));
    unsigned int rest = 1;
    unsigned int res = 1;
    int i = 0;

    while (res != 0) {
        res = number / 8;
        rest = number - (res * 8);
        number = res;
        str[i++] = rest + '0';
    }
    str[i++] = '\0';
    my_putstr(my_revstr(str));
    return (0);
}
