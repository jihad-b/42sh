/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** revstr
*/

#include <stdlib.h>
#include "../../includes/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 1));

    while (len != 0) {
        len = len - 1;
        dest[i] = str[len];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
