/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** set_map.c
*/

#include "setting_up.h"

/**
 * @brief Copie le contenu d'un fichier dans un buffer.
 *
 * @param argv Arguments du programme
 * @param buffer Buffer à remplir
 * @param filestat Statistiques du fichier
 * @return 0 en cas de succès, code d'erreur sinon
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
 * @brief Vérifie si le buffer contient une map valide.
 *
 * @param buffer Buffer à vérifier
 * @return 0 si valide, code d'erreur sinon
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
 * @brief Remplit la structure map à partir du buffer.
 *
 * @param map Structure map à remplir
 * @param buffer Buffer source
 * @return 0 en cas de succès, code d'erreur sinon
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
 * @brief Définit la carte à partir du buffer.
 *
 * @param map Structure map à remplir
 * @param buffer Buffer source
 * @return 0 en cas de succès, code d'erreur sinon
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
 * @brief Définit le motif de la carte.
 *
 * @param map Structure map à remplir
 * @param size Taille de la carte
 * @param pattern Motif à utiliser
 * @return 0 en cas de succès, code d'erreur sinon
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
 * @brief Définit la carte à partir d'un fichier.
 *
 * @param map Structure map à remplir
 * @param argv Arguments du programme
 * @param buffer Buffer à remplir
 * @param filestat Statistiques du fichier
 * @return 0 en cas de succès, code d'erreur sinon
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
