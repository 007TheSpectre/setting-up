/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** set_map.c
*/

#include "setting_up.h"

/**
 * @brief Copie le contenu d'un fichier dans le buffer fourni.
 *
 * @param argv Arguments du programme (argv[1] doit contenir le nom du fichier)
 * @param buffer Zone mémoire déjà allouée pour recevoir les données
 * @param filestat Statistiques du fichier
 * @return 0 si la lecture réussit, 84 sinon
 */
static int cpy_buffer(char **argv, char *buffer, struct stat *filestat)
{
    int fd;
    ssize_t bytesRead;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        free(buffer);
        return my_put_error("open failed\n");
    }
    bytesRead = read(fd, buffer, filestat->st_size);
    if (bytesRead == -1) {
        close(fd);
        free(buffer);
        return my_put_error("read failed\n");
    }
    (buffer)[bytesRead] = '\0';
    close(fd);
    return 0;
}

/**
 * @brief Vérifie que le contenu du buffer correspond au format attendu d'une
 *        map BSQ.
 *
 * La première ligne doit être numérique et définir la hauteur. Le reste du
 * buffer doit être composé uniquement de '.' ou 'o' et de retours à la ligne.
 *
 * @param buffer Buffer à vérifier
 * @return 0 si valide, 84 sinon
 */
static int map_is_correct(char *buffer)
{
    size_t pos;

    for (pos = 0; buffer[pos] != '\n'; pos++)
        if (buffer[pos] < '0' || buffer[pos] > '9') {
            return my_put_error("Invalid map\n");
        }
    for (; buffer[pos]; pos++)
        if (buffer[pos] != '.' && buffer[pos] != 'o' && buffer[pos] != '\n') {
            return my_put_error("Invalid map\n");
        }
    return 0;
}

/**
 * @brief Copie les données du buffer dans la structure map déjà allouée.
 *
 *        La largeur est calculée à partir de la première ligne puis la map est
 *        recopiée telle quelle dans @c map->map.
 *
 * @param map Structure map à remplir
 * @param buffer Buffer source
 * @return 0 en cas de succès, 84 sinon
 */
static int set_map_aux(map_t *map, char *buffer)
{
    int pos = 0;

    for (map->width = 0; *buffer != '\n'; buffer++) {
        map->map[pos] = *buffer;
        map->width++;
        pos++;
    }
    for (; *buffer; buffer++) {
        map->map[pos] = *buffer;
        pos++;
    }
    map->map[pos] = '\0';
    if (!map->map)
        return my_put_error("map->map malloc failed\n");
    return 0;
}

/**
 * @brief Analyse le buffer et remplit la structure map.
 *
 * La première ligne du buffer est interprétée pour récupérer la hauteur de la
 * map. Les lignes suivantes sont copiées dans @c map->map.
 *
 * @param map Structure map à remplir
 * @param buffer Buffer source
 * @return 0 en cas de succès, 84 sinon
 */
static int set_map(map_t *map, char *buffer)
{
    if (map_is_correct(buffer)) {
        return 84;
    }
    for (map->height = 0; *buffer != '\n'; buffer++) {
        map->height *= 10;
        map->height += *buffer - '0';
    }
    buffer++;
    map->map = (char *)malloc(sizeof(char) * (my_strlen(buffer) + 1));
    if (!map->map)
        return my_put_error("map->map malloc failed\n");
    set_map_aux(map, buffer);
    return 0;
}

/**
 * @brief Génère une carte carrée à partir d'un motif répété.
 *
 * @param map Structure map à remplir
 * @param size Taille de la carte (hauteur et largeur identiques)
 * @param pattern Motif à répliquer dans la carte
 * @return 0 en cas de succès, 84 sinon
 */
int set_map_pattern(map_t *map, char *size, char *pattern)
{
    int pos_pattern = 0;
    int len_pattern = my_strlen(pattern);

    map->height = my_getnbr(size);
    map->width = my_getnbr(size);
    map->map = (char *)malloc(map->height * (map->width + 1) + 1);
    if (!map->map)
        return my_put_error("map->map malloc failed\n");
    for (size_t i = 0; i < map->height * (map->width + 1); i++) {
        if (i % (map->width + 1) == map->width) {
            map->map[i] = '\n';
            continue;
        }
        map->map[i] = pattern[pos_pattern];
        pos_pattern++;
        if (pos_pattern == len_pattern)
            pos_pattern = 0;
    }
    map->map[map->height * (map->width + 1)] = '\0';
    return 0;
}

/**
 * @brief Charge une carte depuis un fichier.
 *
 * @param map Structure map à remplir
 * @param argv Arguments du programme
 * @param buffer Buffer à remplir
 * @param filestat Statistiques du fichier
 * @return 0 en cas de succès, 84 sinon
 */
int set_map_map(map_t *map,
    char **argv, char *buffer, struct stat *filestat)
{
    if (cpy_buffer(argv, buffer, filestat))
        return 84;
    if (set_map(map, buffer))
        return 84;
    return 0;
}
