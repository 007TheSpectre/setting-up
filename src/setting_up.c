/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** setting_up.c
*/

#include "setting_up.h"

/**
 * @brief Calcule la valeur minimale autour d'une position dans la map et met à jour indian_map.
 *
 * @param map Structure map
 * @param pos Position courante
 * @param indian_map Tableau de valeurs pour le calcul
 * @return 0
 */
static int indian(map_t *map, size_t pos, size_t *indian_map)
{
    size_t x = pos % (map->width + 1);
    size_t y = pos / (map->width + 1);
    size_t min = ULONG_MAX;

    if (x > 0)
        if (min > indian_map[(x - 1) + (y * map->width)])
            min = indian_map[(x - 1) + (y * map->width)];
    if (y > 0)
        if (min > indian_map[x + ((y - 1) * map->width)])
            min = indian_map[x + ((y - 1) * map->width)];
    if (x > 0 && y > 0)
        if (min > indian_map[(x - 1) + ((y - 1) * map->width)])
            min = indian_map[(x - 1) + ((y - 1) * map->width)];
    if (!x || !y)
        min = 0;
    indian_map[x + (y * map->width)] = min + 1;
    return 0;
}

/**
 * @brief Trouve la plus grande valeur dans indian_map et met à jour la position et la taille dans map.
 *
 * @param map Structure map
 * @param indian_map Tableau de valeurs
 * @return 0
 */
static int find_indian_bigger_pos(map_t *map, size_t *indian_map)
{
    size_t x;
    size_t y;

    map->bigger_size = 0;
    for (size_t i = 0; i < map->height * map->width; i++)
        if (map->bigger_size < indian_map[i])
            map->bigger_size = indian_map[i];
    for (size_t i = 0; i < map->height * map->width; i++)
        if (indian_map[i] == map->bigger_size) {
            x = i % map->width;
            y = i / map->width;
            break;
        }
    for (size_t i = 1; i < map->bigger_size; i++) {
        x--;
        y--;
    }
    map->bigger_pos = (x + (y * (map->width + 1)));
    return 0;
}

/**
 * @brief Place le plus grand carré trouvé dans la map en remplaçant les caractères par 'x'.
 *
 * @param map Structure map
 * @return 0
 */
static int put_carre(map_t *map)
{
    for (size_t x = 0; x < map->bigger_size; x++) {
        for (size_t y = 0; y < map->bigger_size; y++) {
            map->map[map->bigger_pos + x + (y * (map->width + 1))] = 'x';
        }
    }
    return 0;
}

/**
 * @brief Trouve la première position disponible dans la map et initialise la taille du carré à 1.
 *
 * @param map Structure map
 * @return 0
 */
static int one_one(map_t *map)
{
    for (size_t pos = 0; map->map[pos]; pos++)
        if (map->map[pos] == '.') {
            map->bigger_pos = pos;
            map->bigger_size = 1;
            return 0;
        }
    return 0;
}

/**
 * @brief Initialise les valeurs de indian_map à 0 et réinitialise la position et la taille du carré dans map.
 *
 * @param map Structure map
 * @param indian_map Tableau de valeurs
 * @return 0
 */
static int aux(map_t *map, size_t *indian_map)
{
    for (size_t i = 0; i < map->height * map->width; i++)
    indian_map[i] = 0;
    map->bigger_pos = 0;
    map->bigger_size = 0;
    return 0;
}

/**
 * @brief Fonction principale pour configurer la map : calcule les tailles de carré possibles et place le plus grand carré.
 *
 * @param map Structure map
 * @return 0
 */
int setting_up(map_t *map)
{
    size_t pos = 0;
    size_t *indian_map = (size_t *)malloc(
        sizeof(size_t) * map->height * map->width);

    if (!indian_map)
        return 84;
    aux(map, indian_map);
    if (!(map->height > 1 && map->width > 1)) {
        one_one(map);
        put_carre(map);
        return 0;
    }
    for (; map->map[pos]; pos++)
        if (map->map[pos] == '.')
            indian(map, pos, indian_map);
    find_indian_bigger_pos(map, indian_map);
    free(indian_map);
    put_carre(map);
    return 0;
}
