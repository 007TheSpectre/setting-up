/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** my_strlowcase.c
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] = str[i] + 32;
    return str;
}
