/*
** EPITECH PROJECT, 2024
** my_str_isalpha.c
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z')))
            return 0;
    return 1;
}
