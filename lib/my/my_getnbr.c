/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** my_getnbr.c
*/

static void is_positiv(char const *str, unsigned int i, int *result)
{
    for (; str[i] <= '9' && str[i] >= '0'; i++) {
        *result = *result * 10;
        *result = *result + (str[i] - '0');
        if (*result <= 0) {
            *result = 0;
            break;
        }
    }
}

static void is_negativ(char const *str, unsigned int i, int *result)
{
    for (; str[i] <= '9' && str[i] >= '0'; i++) {
        *result = *result * 10;
        *result = *result - (str[i] - '0');
        if (*result >= 0) {
            *result = 0;
            break;
        }
    }
}

static void my_getnbr_aux(char const *str, unsigned int i, int *result)
{
    char if_negativ = 0;

    if (i)
        if (str[i - 1] == '-')
            if_negativ = 1;
    for (; str[i] == '0'; i++);
    if (str[i] <= '9' && str[i] >= '0') {
        *result = *result + (str[i] - '0');
        if (if_negativ)
            *result = *result * -1;
        i++;
    }
    if (if_negativ) {
        is_negativ(str, i, result);
        return;
    }
    is_positiv(str, i, result);
}

int my_getnbr(char const *str)
{
    int result = 0;

    for (unsigned int i = 0; str[i]; i++) {
        if (str[i] <= '9' && str[i] >= '0') {
            my_getnbr_aux(str, i, &result);
            break;
        }
    }
    return result;
}
