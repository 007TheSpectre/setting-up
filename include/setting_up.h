/*
** EPITECH PROJECT, 2024
** setting_up.h
** File description:
** setting_up.h
*/

#ifndef SETTING_UP_H_
    #define SETTING_UP_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <limits.h>
    #include "my.h"

/**
 * @brief Structure représentant la map et ses propriétés.
 */
typedef struct map_s {
    char *map;              /**< Tableau représentant la map */
    size_t height;          /**< Hauteur de la map */
    size_t width;           /**< Largeur de la map */
    size_t bigger_pos;      /**< Position du plus grand carré */
    size_t bigger_size;     /**< Taille du plus grand carré */
} map_t;

/**
 * @brief Résout le problème principal sur la map.
 * @param map Structure map à traiter
 * @return 0 en cas de succès, code d'erreur sinon
 */
int setting_up(map_t *map);

/**
 * @brief Initialise la map à partir d'un fichier.
 * @param map Structure map à remplir
 * @param argv Arguments du programme
 * @param buffer Buffer source
 * @param filestat Statistiques du fichier
 * @return 0 en cas de succès, code d'erreur sinon
 */
int set_map_map(map_t *map,
    char **argv, char *buffer, struct stat *filestat);

/**
 * @brief Initialise la map à partir d'un pattern.
 * @param map Structure map à remplir
 * @param size Taille de la map
 * @param pattern Pattern à utiliser
 * @return 0 en cas de succès, code d'erreur sinon
 */
int set_map_pattern(map_t *map, char *size, char *pattern);

#endif /* SETTING_UP_H_ */
