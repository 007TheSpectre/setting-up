/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    int i;
    int j;

    if (nb < 2)
        return 0;
    for (i = 2; i <= nb / 2; i++) {
        for (j = 2; i * j < nb; j++);
        if (i * j == nb)
            return 0;
    }
    return 1;
}
