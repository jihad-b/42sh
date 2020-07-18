/*
** EPITECH PROJECT, 2019
** tab
** File description:
** tab
*/

#include "./../includes/my.h"

char *find_home(char **env)
{
    int taille = 0;
    int a = 0;
    int b = 0;
    char *dest = NULL;

    for (a = 0; env[a] != NULL; a++){
        if (env[a][0] == 'H' && env[a][1] == 'O' && env[a][2] == 'M'
            && env[a][3] == 'E' && env[a][4] == '=') {
            taille = a;
        }
    }
    dest = malloc(sizeof(char) * my_strlen(env[taille]) - 4);
    for (b = 5; env[taille][b] != '\0'; b++){
            dest[b - 5] = env[taille][b];
        }
    dest[b - 5] = '\0';
    return dest;
}

void cd(char **stock, char **env)
{
    static char *str;
    struct stat s;

    if (stock[1] == NULL) {
        str = malloc(sizeof(char) * 280), getcwd(str, 280);
        chdir(find_home(env));
        return;
    }
    if (my_strcmp(stock[1], "-") == 0) {
        chdir(str);
        return;
    }
    if (stat(stock[1], &s) == -1)
        my_printf("%s: No such file or directory.\n", stock[1]);
    else if (!S_ISDIR(s.st_mode))
        my_printf("%s: Not a directory.\n", stock[1]);
    else {
        str = malloc(sizeof(char) * 280), getcwd(str, 280);
        chdir(stock[1]);
    }
}

int nb_c(char *path)
{
    int a = 0;
    int c = 0;
    int temp = 0;

    for (;path[a] != '/';a++);
    for (; path[a] != '\0'; a++) {
        for (;path[a] != '/';a++) {
            temp++;
        }
        if (temp >= c)
            c = temp;
        temp = 0; }
    return c;
}
