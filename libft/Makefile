# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgasco-g <dgasco-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 23:36:25 by dgasco-g          #+#    #+#              #
#    Updated: 2025/02/23 17:23:04 by dgasco-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=libft.a

SRC	= ft_isascii.c \
	ft_memmove.c	\
	ft_strlcpy.c	\
	ft_toupper.c	\
	ft_bzero.c		\
	ft_isdigit.c	\
	ft_memset.c		\
	ft_strlen.c		\
	ft_isalnum.c	\
	ft_isprint.c	\
	ft_strchr.c		\
	ft_strrchr.c	\
	ft_isalpha.c	\
	ft_memcpy.c		\
	ft_strlcat.c	\
	ft_tolower.c	\
	ft_strncmp.c	\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_strnstr.c	\
	ft_atoi.c		\
	ft_calloc.c		\
	ft_strdup.c		\
	ft_substr.c		\
	ft_strjoin.c	\
	ft_strtrim.c	\
	ft_split.c		\
	ft_itoa.c		\
	ft_strmapi.c	\
	ft_striteri.c	\
	ft_putchar_fd.c \
	ft_putstr_fd.c	\
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c
		
		
 
OBJS	= $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc libft.a $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
