/*
** EPITECH PROJECT, 2024
** my_strupcase.c
** File description:
** my_strupcase.c
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] = str[i] - 32;
    return str;
}
