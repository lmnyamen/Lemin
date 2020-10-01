NAME = lem-in

DIR = ./lemin_files/

LIBRARY_NAME = libft.a
LIBRARY_DIR = ./libft/
LIBRARY = $(addprefix $(LIBRARY_DIR), $(LIBRARY_NAME))

FLAGS = -Wall  -Wextra -Wextra

FUNCTIONS =	moveants.c\
			output.c\
			make.c\
			lemin.c\
			map.c\
			paths.c\
			pathfunc.c\
			clean.c

FILES = $(addprefix $(DIR), $(FUNCTIONS))

@OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBRARY_NAME) 
	@echo "::: CREATING (Lem-in) :::"
	@gcc $(FLAGS) -o $(NAME) $(FILES) $(LIBRARY) 
	@echo "--- Lem-in ---"

$(LIBRARY_NAME):
	@echo "::: CREATING (LIBFT) :::"
	@make -C $(LIBRARY_DIR)
	@echo "--- LIBFT ---"

clean:
	@echo ">>> !!! CLEANING !!! <<<"
	@make clean -C $(LIBRARY_DIR)
	@echo ">>> CLEAN ! <<<"

fclean:
	@echo ">>> !!! CLEANING !!! <<<"
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBRARY_DIR)
	@echo ">>> FCLEAN ! <<<"

re: fclean all

done: re clean