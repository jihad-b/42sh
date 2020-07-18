/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** find_cmd
*/

#include "my.h"

char *find_fisrt_cmd(char *cmd)
{
    int nb = 0;
    char *dest = NULL;

    for (int a = 0; cmd[a] != '\0'; a++)
        if (cmd[a] == '|') {
            nb = a - 1;
            break;
        }
    dest = malloc(sizeof(char) * nb + 1);
    dest = fill_cmd(dest, cmd, nb, 0);
    return dest;
}

char *find_two_cmd(char *cmd)
{
    int nb = 0, nbr = 0;
    char *dest = NULL;

    for (int a = 0; cmd[a] != '\0'; a++)
        if (cmd[a] ==  '|') {
            nb = a + 1;
            break;
        }
    for (int a = nb; cmd[a] != '\0'; a++)
        if (cmd[a] == ';' || cmd[a] == '>' ||
            cmd[a] == '|' || cmd[a] == '<') {
            nbr = a - 1;
            break;
        } else if (cmd[a + 1] == '\0') {
            nbr = a;
            break;
        }
    dest = malloc(sizeof(char) * nbr - nb + 1);
    dest = fill_cmd(dest, cmd, nbr, nb);
    return dest;
}

char *find_third_cmd(char *cmd)
{
    int nb = find_pipe(cmd);
    int nbr = 0;
    char *dest = NULL;

    for (int a = nb; cmd[a] != '\0'; a++)
        if (cmd[a] == ';' || cmd[a] == '>' ||
cmd[a] == '|' || cmd[a] == '<'|| cmd[a + 1] == '\0') {
            nbr = a;
            break;
        }
    dest = malloc(sizeof(char) * nbr - nb + 1);
    dest = fill_cmd(dest, cmd, nbr, nb);
    return dest;
}

char *fill_cmd(char *dest, char *cmd, int nbr, int nb)
{
    for (int c = 0, d = nb; d != nbr + 1; d++) {
        if (cmd[d] != ' ')
            dest[c] = cmd[d], c++;
        else if (cmd[d] == ' ' && (cmd[d + 1] != ' ' &&
cmd[d + 1] != '\0'))
            dest[c] = cmd[d], c++;
        if (cmd[d + 1] == '\0')
            cmd[c + 1] = '\0';
    }
    return dest;
}
