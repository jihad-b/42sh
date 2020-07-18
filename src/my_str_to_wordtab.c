/*
** EPITECH PROJECT, 2020
** tkt
** File description:
** tkt
*/

#include <stdlib.h>
#include "./../includes/my.h"

int nb_of_line(char *str, char c)
{
    int len = 0;
    int i = 0;

    while (str[i] != 0) {
        if (str[i] == c || str[i] == '\t')
            len += 1;
        i += 1;
    }
    return (len + 1);
}

char **my_str_to_dtab(char *str, char c)
{
    char **tab;
    int i = 0, j = 0, s = 0, len = 0;

    if (str != NULL)
        len = nb_of_line(str, c);
    if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
        return (NULL);
    while (str[s] != '\0') {
        if ((tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
            return (NULL);
        for (;str[s] != '\0' && (str[s] == c || str[s] == '\t'); s++);
        while (str[s] != '\0' && str[s] != c && str[s] != '\t')
            tab[i][j++] = str[s++];
        tab[i][j] = '\0';
        if (str[s] != '\0')
            s += 1;
        i += 1, j = 0;
    } if (tab[i - 1][0] == '\0') tab[i - 1] = NULL;
    else tab[i] = NULL;
    return (tab);
}