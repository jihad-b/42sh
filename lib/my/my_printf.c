/*
** EPITECH PROJECT, 2019
** mprintf
** File description:
** mprintf
*/

#include <stdarg.h>
#include "../../includes/my.h"

int my_printf(char const *str, ...)
{
    int a = 0;
    va_list params;

    va_start(params, str);
    while (str[a] != '\0') {
        if (str[a] != '%') {
            my_putchar(str[a]);
        }
        a = printh(params, str, a);
        a = print_o_b(params, str, a);
        a = print_s_s(params, str, a);
        a = print_d_mod(params, str, a);
        a += 1;
    }
    va_end(params);
    return (0);
}
