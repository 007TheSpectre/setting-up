/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** my_strncat.c
*/

char *my_strncat(char *dest, char const *src, int n)
{
    char *dest_return = dest;

    for (; *dest; dest++);
    for (int i = 0; i < n && *src; i++) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_return;
}
