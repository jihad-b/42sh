/*
** EPITECH PROJECT, 2019
** libprint
** File description:
** libprint
*/

#include <stdarg.h>
#include "../../includes/my.h"

int print_s_s(va_list params, char const *str, int a)
{
    if (str[a] == '%' && str[a+1] == 'S') {
        print_s(va_arg(params, char *));
        a += 1;
    }
    if (str[a] == '%' && str[a+1] == 's') {
        my_putstr(va_arg(params, char *));
        a += 1;
    }
    return (a);
}

int print_d_mod(va_list params, char const *str, int a)
{
    if (str[a] == '%' && str[a+1] == 'i') {
        my_put_nbr(va_arg(params, int));
        a += 1;
    }
    if (str[a] == '%' && str[a+1] == 'd') {
        my_put_nbr(va_arg(params, int));
        a += 1;
    }
    if (str[a] == '%' && str[a+1] == '%') {
        my_putchar('%');
        a += 1;
    }
    if (str[a] == '%' && str[a+1] == 'c') {
        my_putchar(va_arg(params, int));
        a += 1;
    }
    return (a);
}
