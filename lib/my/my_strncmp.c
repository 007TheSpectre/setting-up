/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; s1[i] && s2[i] && i < n; i++) {
        if (s1[i] < s2[i])
            return s1[i] - s2[i];
        if (s1[i] > s2[i])
            return s1[i] - s2[i];
    }
    if (i == n)
        return 0;
    if (s1[i] < s2[i])
        return s1[i] - s2[i];
    if (s1[i] > s2[i])
        return s1[i] - s2[i];
    return 0;
}
