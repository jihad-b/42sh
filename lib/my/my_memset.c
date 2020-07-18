/*
** EPITECH PROJECT, 2019
** memsetc
** File description:
** memsetc
*/

int my_memset(char *buffer, char chara, int size)
{
    for (int a = 0;a < size;a++) {
        buffer[a] = chara;
    }
    return (0);
}
