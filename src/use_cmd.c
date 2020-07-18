/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** use_cmd
*/

#include "my.h"

int use_cmd_point(shell_s *shell)
{
    int tmp = 0;
    char *lines = NULL, *str = NULL;

    for (int b = 0; shell->line[b] != '\0'; b++) {
        if (shell->line[b] == ';' ||
        (shell->line[b] == '&' && shell->line[b + 1] == '&')) {
            if ((lines = find_cmd(shell->line, b, tmp)) == NULL)
                return 84;
            tmp = b + 1;
            if (shell->line[b] == '&')
                tmp++;
            if (exec_pipe(shell->environ, lines, shell) == 0) {
                if ((shell->stock = my_str_to_dtab(lines, ' ')) == NULL)
                    return 84;
                loop(shell, str);
                if (shell->environ == NULL)
                    return 84;
            }
        }
    } return tmp;
}

static void use_cmd_final_point(shell_s *shell, char *str)
{
    if (exec_pipe(shell->environ, shell->line, shell) == 0) {
        if ((shell->stock = my_str_to_dtab(shell->line, ' ')) == NULL) {
            shell->environ = NULL;
            return;
        }
        loop(shell, str);
        if (shell->environ == NULL)
            return;
    }
}

static void use_cmd_final(shell_s *shell, char *lines, int tmp, char *str)
{
    if ((lines = find_cmd(shell->line,
    my_strlen(shell->line), tmp)) == NULL) {
        shell->environ = NULL;
        return;
    }
    if (exec_pipe(shell->environ, lines, shell) == 0) {
        if ((shell->stock = my_str_to_dtab(lines, ' ')) == NULL) {
            shell->environ = NULL;
            return;
        }
        loop(shell, str);
        if (shell->environ == NULL)
            return;
    }
}

void use_cmd(shell_s *shell, int tmp)
{
    char *lines = NULL, *str = NULL;

    if (tmp == 0)
        use_cmd_final_point(shell, str);
    else
        use_cmd_final(shell, lines, tmp, str);
}

int find_pipe(char *cmd)
{
    int nb = 0;
    int z = 0;

    for (z = 0; cmd[z] != '\0'; z++)
        if (cmd[z] ==  '|') {
            nb = z + 1;
            break;
        }
    z++;
    for (; cmd[z] != '\0'; z++)
        if (cmd[z] ==  '|') {
            nb = z + 1;
            break;
        }
    return nb;
}
