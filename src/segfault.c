/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** print_seg
*/

#include "my.h"

static void printseg(int status)
{
    if (WCOREDUMP(status))
        my_perror("Segmentation fault (core dumped)\n");
    else
        my_perror("Segmentation fault\n");
}

static void printfloat(int status)
{
    if (WCOREDUMP(status))
        my_perror("Floating exception (core dumped)\n");
    else
        my_perror("Floating exception\n");
}

void check_seg(void)
{
    int child_status;

    wait(&child_status);
    if (WIFSIGNALED(child_status)) {
        if (WTERMSIG(child_status) == SIGSEGV)
            printseg(child_status);
        if (WTERMSIG(child_status) == SIGFPE)
            printfloat(child_status);
    }
}
