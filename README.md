# Setting Up

**Setting Up** est un projet écrit en C dont le but est de rechercher le plus grand carré libre dans une grille en évitant les obstacles. L'algorithme s'appuie sur la programmation dynamique et affiche la carte résultante en remplaçant le contenu du carré maximal par `x`.

## Compilation

Un `Makefile` est fourni à la racine du dépôt. Pour compiler le programme ainsi que la librairie utilitaire située dans `lib/my`, exécutez simplement :

```sh
make
```

Les règles classiques `clean`, `fclean` et `re` sont disponibles pour nettoyer ou recompiler complètement le projet.

## Utilisation

```sh
./setting_up <fichier>
```

- `<fichier>` doit contenir sur sa première ligne le nombre de lignes de la carte.
- Les caractères `.` représentent une case libre et `o` un obstacle.

Le programme peut également générer lui‑même une carte :

```sh
./setting_up <taille> <motif>
```

- `<taille>` correspond à la largeur et à la hauteur voulues.
- `<motif>` est une séquence composée de `.` et `o` qui sera répétée pour former la carte.

Après traitement, la carte est affichée avec des `x` indiquant la zone la plus grande possible.

## Documentation Doxygen

Le fichier `Doxyfile` présent à la racine contient la configuration de la documentation. Pour la générer :

```sh
doxygen Doxyfile
```

La documentation sera alors placée dans le dossier `doc/`. Ouvrez `doc/html/index.html` dans votre navigateur pour la consulter.

