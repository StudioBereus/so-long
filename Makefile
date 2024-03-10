# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 13:28:39 by chhoflac          #+#    #+#              #
#    Updated: 2024/03/11 00:38:25 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

SCRS = sources/flood_fill.c \
		sources/get_elements.c \
		sources/main.c \
		sources/map_checking.c \
		sources/get_map.c \
		sources/graphisms.c \
		sources/set.c \
		sources/mlx_activate.c \
		sources/keyboard_inputs.c

OBJS_SO_LONG = $(SCRS:.c=.o)

MLX = MLX/build/libmlx42.a

CC = cc

CFLAGS = -Werror -Wextra -Wall -g3

NAME = so_long

EXEC = a.out


all : $(NAME)

$(NAME) : $(OBJS_SO_LONG) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -ldl -lglfw -pthread -lm  $(OBJS_SO_LONG) $(LIBFT) $(MLX) -o $(NAME) 
	
$(LIBFT) :
	$(MAKE) -C libft

$(MLX):
	cd MLX && cmake -B build && make -C build

$(MLX)re:
	cd MLX && rm -rf build && cmake -B build && make -C build

$(MLX)clean:
	rm -rf MLX/build

clean : $(MLX)clean
	$(RM) $(OBJS_SO_LONG)
	$(MAKE) -C libft fclean
	
fclean : clean
	$(RM) $(NAME)
	
re : fclean all

.PHONY : all clean fclean re 
