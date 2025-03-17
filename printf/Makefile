# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 20:59:13 by dgasco-g          #+#    #+#              #
#    Updated: 2025/02/23 17:23:02 by dgasco-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS = print.c \
		print_hex.c \
		printf_p.c  \
		ft_printf.c \
	
all: $(NAME)

AR = ar

ARFLAGS = rcs

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re