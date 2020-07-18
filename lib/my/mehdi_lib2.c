/*
** EPITECH PROJECT, 2020
** mehdilib
** File description:
** 42sh
*/
#include "../../includes/my.h"

char **delarr(char **tab, unsigned int delete)
{
    for (int i = delete; tab[i] != NULL; i++) {
        tab[i] = tab[i + 1];
    }
    return (tab);
}

char *write_inside(char *str, char c, int place)
{
    int size = my_strlen(str);
    int i = size + 1;

    for (; i > place; i--)
        str[i] = str[i - 1];
    str[i] = c;
    return (str);
}

char *remplace_word_by_another(char *src, char *dst, char *new)
{
    char **tab = strtoarray(src, ' ');
    char *str = "";
    int boole = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[0], dst) == 0 && boole == 0) {
            tab[0] = new;
            boole = 1;
        }
        str = my_strcatmulti(3, str, " ", tab[i]);
        
    }
    del(str, 0);
    return (str);
}

char *del_char(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == 39 || str[i] == '(' || str[i] == ')') {
            str = del(str, i);
            i--;
        }
    return (str);
}
