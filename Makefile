NAME = so_long

CC = gcc
# FLAGS = -Wall -Werror -Wextra -L LeakSanitizer -llsan -lc++
FLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

SRCS = main.c\
	   util.c\
	   check_map.c\
	   textures.c\
	   key_press.c\
	   path_.c\
	   free.c

RM = rm -f

OBJ = $(SRCS:%.c=%.o)

all: clone_MLX $(NAME)

clone_MLX:
	@if [ -e "MLX42" ]; then \
		echo "up to date"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd MLX42; \
		cmake -B build; \
		make -C build -j4; \
		cd MLX42; cmake .; \
	fi

$(NAME): $(OBJ) 
	make -C ./libft2
	make -C MLX42
	$(CC) $(FLAGS) $(OBJ) libft2/libft.a MLX42/libmlx42.a -lglfw -L ~/.brew/cellar/glfw/3.3.8/lib -o $(NAME)

clean:
	make clean -C libft2/
	# rm -fr ./MLX42
	# make clean -C MLX42/
	-@$(RM) $(OBJ)

fclean: clean
	make fclean -C libft2/
	# make fclean -C MLX42/
	rm -fr ./MLX42
	-@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re