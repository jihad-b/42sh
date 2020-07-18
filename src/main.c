/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    shell_s shell;
    shell.environ = copy_env(env);
    int tmp = 0;

    while (1) {
        my_printf("\e[33m[42SH§]\e[0m");
        init(&shell);
        if (my_strlen(shell.line) != 0) {
            if ((tmp = use_cmd_point(&shell)) == 84)
                return 84;
            use_cmd(&shell, tmp);
            if (shell.environ == NULL)
                return 84;
        }
    }
}
