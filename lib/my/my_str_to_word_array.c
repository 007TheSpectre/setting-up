/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include "my.h"

static int is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

static int get_nb_word(char const *str)
{
    int nb_word = 0;
    char in_word = 0;

    for (; *str; str++) {
        if (is_alphanumeric(*str) && !in_word) {
            nb_word++;
            in_word = 1;
            continue;
        }
        if (!is_alphanumeric(*str) && in_word) {
            in_word = 0;
        }
    }
    return nb_word;
}

static char **set_word_array(char **word_array, char const *str, int nb_word)
{
    int word_len;

    for (int i = 0; i < nb_word; i++) {
        for (; !is_alphanumeric(*str) && *str; str++);
        for (word_len = 0; is_alphanumeric(str[word_len]); word_len++);
        word_array[i] = malloc(sizeof(char) * (word_len + 1));
        my_strncat(word_array[i], str, word_len);
        for (; is_alphanumeric(*str); str++);
    }
    word_array[nb_word] = NULL;
    return word_array;
}

char **my_str_to_word_array(char const *str)
{
    int nb_word = get_nb_word(str);
    char **word_array = malloc(sizeof(char *) * (nb_word + 1));

    word_array = set_word_array(word_array, str, nb_word);
    return word_array;
}
