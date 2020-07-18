/*
** EPITECH PROJECT, 2020
** set
** File description:
** unset
*/

#include "../includes/my.h"

char *tab2(char **environ, int size, int s)
{
    char *str = NULL;

    for (size = 0; environ[s][size] != '='; size++);
    str = malloc(sizeof(char) * size + 1);
    for (size = 0; environ[s][size] != '='; size++)
        str[size] = environ[s][size];
    return str;
}

char **tabf(char **tab, int s, int i, char **environ)
{
    int j = 0;
    int a = 0;

    tab[i] = malloc(sizeof(char) * (my_strlen(environ[s]) + 1));
    while (environ[s][a] != '\0')
        tab[i][j++] = environ[s][a++];
    tab[i][j] = '\0', a += 1, i += 1, j = 0;
    return tab;
}

char **strunset(char **environ, int nbr, char **stock)
{
    char **tab;
    char *str;
    int i = 0, a = 0, size = 0;

    for (; environ[nbr] != NULL; nbr++);
    tab = malloc(sizeof(char *) * (nbr));
    for (int s = 0; environ[s] != NULL; s++) {
        str = tab2(environ, size, s);
        if ((my_strcmp(stock[1], str) == 0)) {
            s++;
            if (environ[s] == NULL) {
                i--, tab[s] = NULL;
                return tab;
            }
        }
        tab = tabf(tab, s, i, environ);
        a += 1, i += 1;
    }
    i++, tab[i] = NULL;
    return (tab);
}

char **unsetenvr(char **envir, char **stock)
{
    int size = 0;
    int a = 0;
    int nbr = 0;
    char *str;
    char **buffer;

    for (; envir[nbr] != NULL; nbr++){
        for (size = 0; envir[nbr][size] != '='; size++);
        str = malloc(sizeof(char) * size + 1);
        for (size = 0; envir[nbr][size] != '='; size++)
            str[size] = envir[nbr][size];
        if ((my_strcmp(stock[1], str) == 0)) {

            buffer = strunset(envir, a, stock);
            return buffer;
        }
    }
    return envir;
}

char **check_set_or_unset(char **environ, char **stock)
{
    if (my_strcmp(stock[0], "setenv") == 0)
        if (stock[1] != NULL)
            environ = setenvr(environ, stock);
        else
            for (int a = 0; environ[a] != NULL; a++)
                my_printf("%s\n", environ[a]);
    else if (stock[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
    } else
        environ = unsetenvr(environ, stock);
    return environ;
}
