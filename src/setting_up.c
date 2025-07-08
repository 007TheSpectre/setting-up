/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** setting_up.c
*/

#include "setting_up.h"

/**
 * @brief Met à jour @p indian_map pour la position donnée.
 *
 * Calcule la taille du plus grand carré terminant à la position @p pos en se
 * basant sur les valeurs voisines du tableau.
 *
 * @param map Structure map
 * @param pos Position courante dans la chaîne de la map
 * @param indian_map Tableau de travail contenant les tailles calculées
 * @return 0
 */
static int indian(map_t *map, size_t pos, size_t *indian_map) {
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
 * @brief Cherche la valeur maximale calculée dans @p indian_map et en déduit la
 *        position du plus grand carré.
 *
 * @param map Structure map
 * @param indian_map Tableau des tailles calculées
 * @return 0
 */
static int find_indian_bigger_pos(map_t *map, size_t *indian_map) {
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
 * @brief Remplace par 'x' toutes les cases du plus grand carré détecté.
 *
 * @param map Structure map
 * @return 0
 */
static int put_carre(map_t *map) {
  for (size_t x = 0; x < map->bigger_size; x++) {
    for (size_t y = 0; y < map->bigger_size; y++) {
      map->map[map->bigger_pos + x + (y * (map->width + 1))] = 'x';
    }
  }
  return 0;
}

/**
 * @brief Cherche la première case libre afin d'initialiser un carré de taille
 *        1 lorsque la carte est trop petite.
 *
 * @param map Structure map
 * @return 0
 */
static int one_one(map_t *map) {
  for (size_t pos = 0; map->map[pos]; pos++)
    if (map->map[pos] == '.') {
      map->bigger_pos = pos;
      map->bigger_size = 1;
      return 0;
    }
  return 0;
}

/**
 * @brief Réinitialise le tableau de travail et les informations sur le plus
 *        grand carré trouvé.
 *
 * @param map Structure map
 * @param indian_map Tableau de valeurs
 * @return 0
 */
static int aux(map_t *map, size_t *indian_map) {
  for (size_t i = 0; i < map->height * map->width; i++)
    indian_map[i] = 0;
  map->bigger_pos = 0;
  map->bigger_size = 0;
  return 0;
}

/**
 * @brief Algorithme principal : calcule les tailles de carré possibles et
 *        place le plus grand dans la carte.
 *
 * @param map Structure map
 * @return 0
 */
int setting_up(map_t *map) {
  size_t pos = 0;
  size_t *indian_map =
      (size_t *)malloc(sizeof(size_t) * map->height * map->width);

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
