/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** main.c
*/

#include "setting_up.h"

/**
 * @brief Vérifie que la chaîne fournie ne contient que les caractères '.' ou
 * 'o'.
 *
 * @param pattern Chaîne à analyser
 * @return 1 si la chaîne est valide, 0 sinon
 */
static int is_pattern(char *pattern) {
  for (; *pattern; pattern++)
    if (*pattern != '.' && *pattern != 'o')
      return 0;
  return 1;
}

/**
 * @brief Valide les arguments et réserve le buffer adapté selon que l'entrée
 *        est un fichier ou un motif à générer.
 *
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @param buffer Pointeur vers le buffer à allouer
 * @param filestat Informations sur le fichier à lire
 * @return 1 si un motif doit être généré, 0 si un fichier est utilisé, 84 en
 *         cas d'erreur
 */
int error_handling(int argc, char **argv, char **buffer,
                   struct stat *filestat) {
  if (argc < 2)
    return my_put_error("Invalid nb params\n");
  if (my_str_isnum(argv[1])) {
    if (argc < 3)
      return my_put_error("Invalid nb params\n");
    if (!is_pattern(argv[2]))
      return my_put_error("Invalid pattern\n");
    *buffer = (char *)malloc(my_getnbr(argv[1]) * (my_getnbr(argv[1]) + 1) + 1);
    if (!*buffer)
      return my_put_error("malloc failed\n");
    return 1;
  }
  if (stat(argv[1], filestat) == -1)
    return my_put_error("Invalid file name\n");
  *buffer = (char *)malloc(filestat->st_size + 1);
  if (!*buffer)
    return my_put_error("malloc failed\n");
  return 0;
}

/**
 * @brief Libère la mémoire allouée pour le buffer et la structure map.
 *
 * @param buffer Buffer à libérer
 * @param map Structure map à libérer
 */
static void free_data(char *buffer, map_t *map) {
  if (buffer)
    free(buffer);
  if (map->map)
    free(map->map);
  if (map)
    free(map);
}

/**
 * @brief Initialise la structure map en fonction des arguments reçus.
 *
 *        Selon les paramètres, la carte est lue depuis un fichier ou bien
 *        générée à partir d'un motif.
 *
 * @param map Structure map à remplir
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @param buffer Pointeur vers le buffer à allouer
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int main_aux(map_t *map, int argc, char **argv, char **buffer) {
  struct stat filestat;
  int temp = error_handling(argc, argv, buffer, &filestat);

  if (temp == 84)
    return 84;
  if (!temp)
    if (set_map_map(map, argv, *buffer, &filestat))
      return 84;
  if (temp == 1)
    if (set_map_pattern(map, argv[1], argv[2]))
      return 84;
  return 0;
}

/**
 * @brief Point d'entrée principal du programme.
 *
 *        Alloue la structure principale, lance l'initialisation de la map puis
 *        exécute l'algorithme de résolution.
 *
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @return 0 en cas de succès, 84 en cas d'erreur
 */
int main(int argc, char **argv) {
  char *buffer = NULL;
  map_t *map = (map_t *)malloc(sizeof(map_t));

  if (!map)
    return my_put_error("map malloc failed\n");
  if (main_aux(map, argc, argv, &buffer))
    return 84;
  if (setting_up(map))
    return 84;
  my_putstr(map->map);
  free_data(buffer, map);
  return 0;
}
