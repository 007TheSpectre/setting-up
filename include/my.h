/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

/**
 * @brief Élève nb à la puissance p (récursif).
 */
int my_compute_power_rec(int nb, int p);
/**
 * @brief Calcule la racine carrée entière de nb.
 */
int my_compute_square_root(int nb);
/**
 * @brief Retourne le plus petit nombre premier >= nb.
 */
int my_find_prime_sup(int nb);
/**
 * @brief Convertit une chaîne en entier.
 */
int my_getnbr(char const *str);
/**
 * @brief Affiche 'N' si n est négatif, 'P' sinon.
 */
int my_isneg(int n);
/**
 * @brief Vérifie si nb est un nombre premier.
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
 * @brief Affiche une chaîne en hexadécimal (mémoire).
 */
int my_showmem(char const *str, int size);
/**
 * @brief Affiche une chaîne avec caractères non imprimables en hexadécimal.
 */
int my_showstr(char const *str);
/**
 * @brief Trie un tableau d'entiers.
 */
void my_sort_int_array(int *array, int size);
/**
 * @brief Met la première lettre de chaque mot en majuscule.
 */
char *my_strcapitalize(char *str);
/**
 * @brief Concatène src à la fin de dest.
 */
char *my_strcat(char *dest, char const *src);
/**
 * @brief Compare deux chaînes de caractères.
 */
int my_strcmp(char const *s1, char const *s2);
/**
 * @brief Copie src dans dest.
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
 * @brief Retourne la longueur d'une chaîne.
 */
int my_strlen(char const *str);
/**
 * @brief Met tous les caractères d'une chaîne en minuscules.
 */
char *my_strlowcase(char *str);
/**
 * @brief Concatène src à dest sur nb caractères max.
 */
char *my_strncat(char *dest, char const *src, int nb);
/**
 * @brief Compare deux chaînes sur n caractères.
 */
int my_strncmp(char const *s1, char const *s2, int n);
/**
 * @brief Copie n caractères de src dans dest.
 */
char *my_strncpy(char *dest, char const *src, int n);
/**
 * @brief Cherche to_find dans str.
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
 * @brief Découpe une chaîne en mots (tableau).
 */
char **my_str_to_word_array(char const *str);
/**
 * @brief Affiche un message d'erreur sur la sortie d'erreur.
 */
int my_put_error(const char *err_msg);

#endif /* MY_H_ */
