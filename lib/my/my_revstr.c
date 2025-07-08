/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** my_revstr.c
*/

#include "my.h"

char *my_revstr(char *str)
{
    char temp;
    int len = my_strlen(str);

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}
