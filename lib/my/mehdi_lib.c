/*
** EPITECH PROJECT, 2020
** mehdi lib
** File description:
** 42sh
*/
#include "../../includes/my.h"

void my_putarray(char **array)
{
    int column;

    for (column = 0; array[column]; column++);
    for (int i = 0; i < column; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}

void my_putarrfd(char **array, int fd)
{
    int column = 0;

    for (column = 0; array[column]; column++);
    for (int i = 0; i < column; i++) {
        write(fd, array[i], my_strlen(array[i]));
        write(fd, "\n", 1);
    }
}

char *my_strcatmulti(int nb, char *str, ...)
{
    va_list list;
    char *str2 = NULL;

    va_start(list, str);
    for (int i = 0; i < nb - 1; i++) {
        str2 = va_arg(list, char *);
        str = my_strcat(str, str2);
    }
    return (str);
}

char *del(char *str, int place)
{
    for (int i = place; str[i] != 0; i++)
        str[i] = str[i + 1];
    return (str);
}

char *my_arr_to_str(char **tab)
{
    char *str = "";

    for (int i = 0; tab[i] != NULL; i++)
        str = my_strcatmulti(3, str, " ", tab[i]);
    return (del(str, 0));

}
