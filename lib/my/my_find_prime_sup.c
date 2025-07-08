/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** my_find_prime_sup.c
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    for (; !my_is_prime(nb); nb++);
    return nb;
}
