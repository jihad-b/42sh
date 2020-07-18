/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** Task05
*/

#include "../../includes/my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
