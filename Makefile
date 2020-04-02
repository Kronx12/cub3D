CC=gcc
CFLAGS=-Wall -Wextra -Werror -I ./includes/
MLX_FLAGS=-framework OpenGL -framework AppKit -g
NAME=Cub3D
SRCS=./srcs/free_structures.c \
	 ./srcs/hook.c \
	 ./srcs/hook_movement.c \
	 ./srcs/init_structures.c \
	 ./srcs/load_textures.c \
	 ./srcs/load_textures_global.c \
	 ./srcs/main.c \
	 ./srcs/parsing_loop.c \
	 ./srcs/parse_map.c \
	 ./srcs/parse_textures.c \
	 ./srcs/parse_utils.c \
	 ./srcs/check_map.c \
	 ./srcs/preform.c \
	 ./srcs/raycast.c \
	 ./srcs/raycast_launch.c \
	 ./srcs/raycast_sprite.c \
	 ./srcs/save_bitmap.c \
	 ./srcs/starter.c
OBJS=$(SRCS:.c=.o)
MLX=./minilibx/libmlx.a
LIBFT=./libft/libft.a
INC=./includes/cub3d.h \
	./includes/key_codes.h \
	./includes/structures_cub3d.h \
	./minilibx/mlx.h \
	./libft/libft.h
RM=rm -f

%.c%.o:
	gcc $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(OBJS):	$(INC)

lib:
	$(MAKE) -C libft
	$(MAKE) -C minilibx

$(NAME): 	$(INC) $(OBJS) lib
	gcc $(CFLAGS) $(MLX) $(LIBFT) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	cd minilibx && make clean
	cd libft && make clean

fclean: 	clean
	$(RM) $(NAME)
	cd minilibx && make clean
	cd libft && make fclean

re:		fclean all

.PHONY: all bonus clean fclean re lib
