/*
** EPITECH PROJECT, 2020
** loop
** File description:
** loop
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include "../includes/my.h"
#include <time.h>

char *path_complet(char *str, char *dpath, char *stock)
{
    str = my_strcat(dpath, "/");
    str = my_strcat(str, stock);
    return str;
}

char *fpath(char **environ)
{
    int a = 0, taille = 0, temp = 0;
    char *dest = NULL;

    for (a = 0; environ[a] != NULL; a++){
        if (environ[a][0] == 'P' && environ[a][1] == 'A' && environ[a][2] == 'T'
            && environ[a][3] == 'H' ) {
            taille = my_strlen(environ[a]);
            temp = a;
        }
        if (environ[a][0] == 'P' && environ[a][1] == 'A' && environ[a][2] == 'T'
            && environ[a][3] == 'H' && environ[a][4] == '=' &&
            environ[a][5] == '\0')
                return NULL;
    }
    if (temp == 0)
        return NULL;
    dest = malloc(sizeof(char) * taille + 1);
    for (int a = 0; environ[temp][a] != '\0'; a++)
        dest[a] = environ[temp][a];
    return dest;
}

