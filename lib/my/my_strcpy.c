/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    unsigned int i;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
