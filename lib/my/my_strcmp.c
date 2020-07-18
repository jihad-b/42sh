/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** mstrcmp
*/

#include <stdlib.h>
#include "./../../includes/my.h"

int my_strcmp(char *s1 , char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 1;
    else if (my_strlen(s1) != my_strlen(s2))
        return 1;
    else
        for (int a = 0; s1[a] != '\0'; a++)
            if (s1[a] != s2[a])
                return 1;
    return (0);
}
