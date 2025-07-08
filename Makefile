##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc

MAKE	=	make

NAME	=	setting_up

SRC_DIR	=	src

OBJ_DIR	=	obj

SRC	=	$(SRC_DIR)/set_map.c \
		$(SRC_DIR)/setting_up.c \
		$(SRC_DIR)/main.c \

OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Wextra -Iinclude/

LIBMY_DIR = lib/my/

LDFLAGS += -Llib/ -lmy

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(MAKE) -C $(LIBMY_DIR)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBMY_DIR) clean
	rm -f $(OBJ)
	-rmdir $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBMY_DIR) fclean
	rm -f $(NAME)
	rm -f unit_tests

run: all
	./$(NAME)

re: fclean all

unit_tests: fclean $(NAME)
	gcc tests/*.c -L. -lmy -Iinclude/ -lcriterion -o unit_tests

tests_run: unit_tests
	./unit_tests || true
