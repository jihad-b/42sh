/*
** EPITECH PROJECT, 2020
** alias
** File description:
** 42sh
*/

#include "my.h"

char *clear_alias(char *oldstr)
{
    char *str = malloc(my_strlen(oldstr) + 2);
    int nb39 = 0;
    int j = 0;

    str = oldstr;
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == 39) {
            nb39++;
            del(str, i);
            i--;
        }
    if (nb39 == 0) {
        for (; str[j] != 0; j++)
            if (str[j] == '\t')
                write_inside(str, '(', j + 1);
        str[j] = ')';
        str[j + 1] = '\0';
    }
    return (str);
}

long long int sizefile(char *filepath)
{
    struct stat sb;

    stat(filepath, &sb);
    return (sb.st_size);
}

void alias(char **tab)
{
    int fd = open(".bash_alias", O_RDWR | O_CREAT | O_APPEND, 0666);
    long long int size = sizefile(".bash_alias");
    char *str = malloc(size);
    char *new_alias = NULL;

    read(fd, str, size);
    if (tab[1] == NULL)
        my_putstr(str);
    else {
        new_alias = my_strcat(tab[1], "\t");
        delarr(tab, 0);
        delarr(tab, 0);
        new_alias = my_strcat(new_alias, my_arr_to_str(tab));
        new_alias = my_strcat(clear_alias(new_alias), "\n");
        write(fd, new_alias, my_strlen(new_alias));
    }
}

char **check_alias(char **tabe)
{
    char *av = my_arr_to_str(tabe);
    int fd = open(".bash_alias", O_RDWR | O_CREAT | O_APPEND, 0666);
    char **tab_alias = NULL;
    char **tab = NULL;
    char **cmd = strtoarray(av, ' ');
    long long int size = sizefile(".bash_alias");
    char *str = malloc(size);

    read(fd, str, size);
    if (str == NULL || str[0] == '\0') return tabe;
    tab = strtoarray(str, '\n');
    for (int i = 0; tab[i] != NULL; i++) {
        tab_alias = strtoarray(tab[i], '\t');
        if (my_strcmp(cmd[0], tab_alias[0]) == 0) {
            av = del_char(remplace_word_by_another(av, cmd[0], tab_alias[1])); 
            return (strtoarray(av, ' '));
        }
    }
    return (tabe);
}

void unalias(char *to_del)
{
    int fd = open(".bash_alias", O_RDWR | O_CREAT, 0666);
    char **tab_alias = NULL;
    char **tab = NULL;
    long long int size = sizefile(".bash_alias");
    char *str = malloc(size);

    read(fd, str, size);
    tab = strtoarray(str, '\n');
    for (int i = 0; tab[i] != NULL; i++) {
        tab_alias = strtoarray(tab[i], '\t');
        if (my_strcmp(tab_alias[0], to_del) == 0) {
            tab = delarr(tab, i);
            remove(".bash_alias");
            fd = open(".bash_alias", O_RDWR | O_CREAT, 0666);
            my_putarrfd(tab, fd);
            return;
        }
    }
}
