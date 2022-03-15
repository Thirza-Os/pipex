# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tosinga <tosinga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 11:18:45 by tosinga           #+#    #+#              #
#    Updated: 2022/03/09 13:20:10 by tosinga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC =		ft_printf.c				\
			ft_strlen.c				\
			ft_printf_char.c		\
			ft_printf_int.c			\
			ft_printf_str.c			\
			ft_printf_unint.c		\
			ft_printf_hexa.c		\
			ft_printf_void.c		\

HEADER	=	libftprintf.h
OBJECTS	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re