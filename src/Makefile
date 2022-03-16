NAME 			= pipex

SRCS 			=	main.c 			\
					utils.c			\
					ft_split.c		\
					utils_split.c

# CFLAGS 			= -Wall -Wextra -Werror
CC				= gcc
HEADER 			= pipex.h

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "maked"

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJECTS)
	@echo "maked clean"

fclean: clean
	@$(RM) $(NAME)
	@echo "maked fclean"

re: fclean all

.PHONY: all clean fclean re