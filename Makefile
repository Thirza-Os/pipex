NAME 			= pipex

SRCS 			= main.c

LIB				= ./libft/libft.a
LIBFT_LOC		= libft
LIBFT_LIB		= libft/libft.a
PRINTF_LOC		= libftprintf
PRINTF_LIB		= libftprintf/libftprintf.a
PRINTF_FLAGS	= -Llibftprintf -lftprintf 
# CFLAGS 			= -Wall -Wextra -Werror
CC				= gcc
HEADER 			= pipex.h

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@$(MAKE) -s -C $(LIBFT_LOC)
	@$(MAKE) -s -C $(PRINTF_LOC)
	@$(CC) $(CFLAGS) $(PRINTF_FLAGS) $(OBJECTS) $(PRINTF_LIB) $(LIB) -o $(NAME)
	@echo "maked"

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -s -C $(dir $(LIB)) clean
	@$(MAKE) -s -C $(PRINTF_LOC) clean
	@echo "maked clean"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(dir $(LIB)) fclean
	@echo "maked fclean"

re: fclean all

.PHONY: all clean fclean re