/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** task01
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;
    for (;a != n; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return (dest);
}
