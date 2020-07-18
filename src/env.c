/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "../includes/my.h"

char **copy_env(char **env)
{
    int nbr = 0;
    char **environ = NULL;

    if (env == NULL)
        return NULL;
    for (; env[nbr] != NULL; nbr++);
    if ((environ = malloc(sizeof(char *) * nbr + 2)) == NULL)
        exit (84);
    for (int a = 0; env[a] != NULL; a++)
        if ((environ[a] = malloc(sizeof(char) * my_strlen(env[a]) + 1)) == NULL)
            exit (84);
    for (int a = 0; env[a] != NULL; a++)
        for (int b = 0; env[a][b] != '\0'; b++)
            environ[a][b] = env[a][b];
    environ[nbr] = NULL;
    return environ;
}

char **strtab(char **environ, int nbr, char **stock)
{
    char **tab;
    int i = 0, j = 0, a = 0;

    for (; environ[nbr] != NULL; nbr++);
    tab = malloc(sizeof(char *) * (nbr + 2));
    for (int s = 0; environ[s] != NULL; s++) {
        a = 0;
        tab[i] = malloc(sizeof(char) * (my_strlen(environ[s]) + 1));
        while (environ[s][a] != '\0')
            tab[i][j++] = environ[s][a++];
        tab[i][j] = '\0', a += 1, i += 1, j = 0;
    }
    tab[i] = malloc(sizeof(char) * (my_strlen(stock[1]) + 1));
    for (int t = 0; stock[1][t] != '\0'; t++, j++)
        tab[i][j] = stock[1][t];
    tab[i][j] = '=', i++, tab[i] = NULL;

    return (tab);
}

char **strtab2(char **environ, int nbr, char **stock)
{
    char **tab;
    int i = 0, j = 0, a = 0;

    for (; environ[nbr] != NULL; nbr++);
    tab = malloc(sizeof(char *) * (nbr + 2));
    for (int s = 0; environ[s] != NULL; s++) {
        a = 0, tab[i] = malloc(sizeof(char) * (my_strlen(environ[s]) + 1));
        while (environ[s][a] != '\0')
            tab[i][j++] = environ[s][a++];
        tab[i][j] = '\0', a += 1, i += 1, j = 0;
    }
    tab[i] = malloc(sizeof(char) * (my_strlen(stock[1]) +
                                    my_strlen(stock[2])) + 1);
    for (int t = 0; stock[1][t] != '\0'; t++, j++)
        tab[i][j] = stock[1][t];
    tab[i][j] = '=', j++;
    for (int t = 0; stock[2][t] != '\0'; t++, j++)
        tab[i][j] = stock[2][t];
    i++, tab[i] = NULL;
    return (tab);
}

char **setenvr(char **envir, char **stock)
{
    int nbr = 0;
    char **buffer;

    for (; envir[nbr] != NULL; nbr++);
    for (int i = 0; stock[1][i] != '\0'; i++)
        if (stock[1][i] == '=') {
            my_printf("setenv: Variable name must contain");
            my_printf(" alphanumeric characters.\n");
            return envir;
        }
    if (stock[2] == NULL)
        buffer = strtab(envir, nbr, stock);
    else
        buffer = strtab2(envir, nbr, stock);
    return buffer;
}

char **setenviron(char **environ, char **stock)
{
    int a = 0;

    for (int i = 0; stock[1][i] != '\0'; i++)
        if (stock[1][i] == '=') {
            my_printf("setenv: Variable name must contain");
            my_printf(" alphanumeric characters.\n");
            return environ;
        }
    for (int i = 0; environ[i] != NULL; i++) {
        for (int c = 0; stock[1][c] == environ[i][c]; c++, a++)
            if (environ[i][c] == '=' && stock[1][c] == '=') {
                environ[i][c + 1] = '\0';
                return environ;
            }
            else if (environ[i][c + 1] == '=' && stock[1][c + 1] == '\0') {
                environ[i][c + 2] = '\0';
                return environ;
            }
    }
    return environ;
}