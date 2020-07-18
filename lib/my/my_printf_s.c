/*
** EPITECH PROJECT, 2019
** %S
** File description:
** %S
*/

#include "../../includes/my.h"

int print_s(char *str)
{
    int nb = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] > 32 && str[a] <= 127) {
            my_putchar(str[a]);
        } else {
            my_putstr("\\");
            nb  = str[a] ;
            if (nb < 8 )
                my_putstr("00");
            if (nb < 32 && nb >= 8)
                my_putchar('0');
            toctal(nb);
        }
    }
}
