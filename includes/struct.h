/*
** EPITECH PROJECT, 2020
** include
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct shell_t
{
    char *line;
    char **dpath;
    char **stock;
    char **environ;
    int check;
    int fd;
    int pid;
}shell_s;

#endif /* !STRUCT_H_ */
