/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** my_compute_square_root.c
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 1)
        return result;
    for (int i = 1; my_compute_power_rec(i, 2) <= nb; i++)
        if (my_compute_power_rec(i, 2) == nb)
            result = i;
    return result;
}
