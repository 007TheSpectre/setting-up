##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc

NAME	=	libmy.a

SRC	=	my_compute_power_rec.c\
		my_compute_square_root.c\
		my_find_prime_sup.c\
		my_getnbr.c\
		my_isneg.c\
		my_is_prime.c\
		my_putchar.c\
		my_put_nbr.c\
		my_putstr.c\
		my_revstr.c\
		my_sort_int_array.c\
		my_strcapitalize.c\
		my_strcat.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strdup.c\
		my_str_isalpha.c\
		my_str_islower.c\
		my_str_isnum.c\
		my_str_isprintable.c\
		my_str_isupper.c\
		my_strlen.c\
		my_strlowcase.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\
		my_strstr.c\
		my_str_to_word_array.c\
		my_strupcase.c\
		my_swap.c\
		my_put_error.c\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
