# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 23:37:59 by dgasco-g          #+#    #+#              #
#    Updated: 2025/03/03 12:30:14 by dgasco-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O3
RM = rm -f

SRC =	map.c map2.c so_long.c utils.c movement.c textures.c

OBJS = $(SRC:.c=.o)

UNAME_S := $(shell uname -s)

MLXFLAGS = -L mlx -lmlx -lX11 -lXext -lbsd -lm

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

MLX = mlx/libmlx.a

all: $(NAME)

%.o: %.c
	$(CC) -I src/ $(CFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C libft 
	
$(MLX):
	$(MAKE) -C mlx 

$(PRINTF):
	$(MAKE) -C printf 

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) printf/libftprintf.a libft/libft.a  $(MLX) $(MLXFLAGS)


sanitize:
	$(eval CFLAGS+=-fsanitize=address,leak -g3)

sani: sanitize re

clean:
	make clean -C mlx
	make clean -C libft
	make clean -C printf
	rm -f $(OBJS)
	


fclean: clean
	make fclean -C libft
	make fclean -C printf
	rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re
