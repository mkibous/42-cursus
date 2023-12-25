SRCS =	so_long.c get_next_line_utils.c get_next_line.c
NAME = game
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = libft/libft.a
PRINT = printf/libftprintf.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRCS:.c=.o)
all: $(LIBFT) $(PRINT) $(NAME)

$(LIBFT) : libft/Makefile
	cd libft && make
$(PRINT) : printf/Makefile
	cd printf && make
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean_libft : libft/Makefile printf/Makefile
	cd libft && make clean
	cd printf && make clean
clean: clean_libft
	$(RM) $(OBJ) 
fclean_libft : libft/Makefile printf/Makefile
	cd libft && make fclean
	cd printf && make fclean
fclean: clean fclean_libft
	$(RM) $(NAME)
re : fclean all