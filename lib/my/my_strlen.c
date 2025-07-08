/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int count = 0;

    for (unsigned int i = 0; str[i]; i++) {
        count++;
    }
    return count;
}
