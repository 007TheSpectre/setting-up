/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** my_strcat.c
*/

char *my_strcat(char *dest, char const *src)
{
    char *str = dest;

    for (; *str; str++);
    for (; *src; src++) {
        *str = *src;
        str++;
    }
    *str = '\0';
    return dest;
}
