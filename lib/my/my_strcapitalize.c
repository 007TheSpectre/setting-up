/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** my_strcapitalize.c
*/

static void lowcase_letter(char *str, int i)
{
    if (!i) {
        str[i] = str[i] - 32;
        return;
    }
    if ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
        || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
        || (str[i - 1] >= '0' && str[i - 1] <= '9'))
        return;
    str[i] = str[i] - 32;
}

static void upcase_letter(char *str, int i)
{
    if (!i)
        return;
    if ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
        || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
        || (str[i - 1] >= '0' && str[i - 1] <= '9'))
        str[i] = str[i] + 32;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            lowcase_letter(str, i);
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            upcase_letter(str, i);
        }
    }
    return str;
}
