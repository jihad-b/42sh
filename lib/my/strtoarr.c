/*
** EPITECH PROJECT, 2019
** str to array
** File description:
** library
*/
#include "../../includes/my.h"

int bnlen(char *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            size++;
    return (size);
}

int linelen(char *str, int i)
{
    int size;

    if (str[i] == '\n')
        i++;
    for (size = 0; str[i] != '\n' && str[i] != '\0'; size++, i++);
    return (size);
}

char **strtoarray(char *str, char sign)
{
    int bnsize = bnlen(str);
    int size = my_strlen(str);
    char **arr = malloc(sizeof(char *)* (bnsize + 2));
    int k = 0;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        arr[k] = malloc(sizeof(char)* linelen(str, i));
        for (int j = 0; str[i] != sign && str[i] != '\0'; j++, i++)
            arr[k][j] = str[i];
        k++;
    }
    return (arr);
}
