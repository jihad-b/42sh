/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** getnbr
*/

int nbr_to_chiff(int nb)
{
    int nbr = 0;

    while (nb != 0) {
        nb = (nb / 10);
        nbr += 1;
    }
    return (nbr);
}
