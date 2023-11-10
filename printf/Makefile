# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 15:54:40 by mkibous           #+#    #+#              #
#    Updated: 2023/11/08 21:13:10 by mkibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	*.c
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rc
RM = rm -f
OBJ = $(SRCS:.c=.o)
$(NAME): ft_printf.h
	$(CC) $(CFLAGS) -c $(SRCS)
	$(LIBC) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
