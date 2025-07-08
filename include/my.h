/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

/**
 * @brief Calcule nb à la puissance p de façon récursive.
 */
int my_compute_power_rec(int nb, int p);
/**
 * @brief Calcule la racine carrée entière d'un nombre.
 */
int my_compute_square_root(int nb);
/**
 * @brief Trouve le plus petit nombre premier supérieur ou égal à nb.
 */
int my_find_prime_sup(int nb);
/**
 * @brief Convertit une chaîne en entier.
 */
int my_getnbr(char const *str);
/**
 * @brief Affiche si un nombre est négatif.
 */
int my_isneg(int n);
/**
 * @brief Vérifie si un nombre est premier.
 */
int my_is_prime(int nb);
/**
 * @brief Affiche un caractère sur la sortie standard.
 */
int my_putchar(char c);
/**
 * @brief Affiche un nombre sur la sortie standard.
 */
int my_put_nbr(int nb);
/**
 * @brief Affiche une chaîne sur la sortie standard.
 */
int my_putstr(char const *str);
/**
 * @brief Inverse une chaîne de caractères.
 */
char *my_revstr(char *str);
/**
 * @brief Affiche une chaîne en mémoire.
 */
int my_showmem(char const *str, int size);
/**
 * @brief Affiche une chaîne avec des caractères non imprimables.
 */
int my_showstr(char const str);
/**
 * @brief Trie un tableau d'entiers.
 */
void my_sort_int_array(int *array, int size);
/**
 * @brief Met la première lettre de chaque mot en majuscule.
 */
char *my_strcapitalize(char *str);
/**
 * @brief Concatène deux chaînes.
 */
char *my_strcat(char *dest, char const *src);
/**
 * @brief Compare deux chaînes.
 */
int my_strcmp(char const *s1, char const *s2);
/**
 * @brief Copie une chaîne dans une autre.
 */
char *my_strcpy(char *dest, char const *src);
/**
 * @brief Vérifie si la chaîne ne contient que des lettres.
 */
int my_str_isalpha(char const *str);
/**
 * @brief Vérifie si la chaîne ne contient que des minuscules.
 */
int my_str_islower(char const *str);
/**
 * @brief Vérifie si la chaîne ne contient que des chiffres.
 */
int my_str_isnum(char const *str);
/**
 * @brief Vérifie si la chaîne ne contient que des caractères imprimables.
 */
int my_str_isprintable(char const *str);
/**
 * @brief Vérifie si la chaîne ne contient que des majuscules.
 */
int my_str_isupper(char const *str);
/**
 * @brief Calcule la longueur d'une chaîne.
 */
int my_strlen(char const *str);
/**
 * @brief Met tous les caractères d'une chaîne en minuscules.
 */
char *my_strlowcase(char *str);
/**
 * @brief Concatène deux chaînes avec une limite de caractères.
 */
char *my_strncat(char *dest, char const *src, int nb);
/**
 * @brief Compare deux chaînes sur n caractères.
 */
int my_strncmp(char const *s1, char const *s2, int n);
/**
 * @brief Copie n caractères d'une chaîne dans une autre.
 */
char *my_strncpy(char *dest, char const *src, int n);
/**
 * @brief Recherche une sous-chaîne dans une chaîne.
 */
char *my_strstr(char *str, char const *to_find);
/**
 * @brief Met tous les caractères d'une chaîne en majuscules.
 */
char *my_strupcase(char *str);
/**
 * @brief Échange deux entiers.
 */
void my_swap(int *a, int *b);
/**
 * @brief Duplique une chaîne de caractères.
 */
char *my_strdup(char const *src);
/**
 * @brief Découpe une chaîne en mots.
 */
char **my_str_to_word_array(char const *str);
/**
 * @brief Affiche un message d'erreur sur la sortie d'erreur.
 */
int my_put_error(const char *err_msg);

#endif /* MY_H_ */
