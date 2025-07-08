/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** my_strstr.c
*/

#include <stddef.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    if (!str && !to_find)
        return str;
    for (; *str; str++)
        if (!my_strncmp(str, to_find, my_strlen(to_find)))
            return str;
    return NULL;
}
