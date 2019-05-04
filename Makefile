# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angkim <angkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 09:30:19 by angkim            #+#    #+#              #
#    Updated: 2019/05/04 11:55:10 by angkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	libft/libft.a \
		main.c \
		read.1.c \
		solve.c

OBJS = $(SRCS:%.c=%.o)

INC = fillit.h

CFLAGS = -Wall -Werror -Wextra 

LIB_DIR = libft

all: $(NAME)

$(NAME):
	make -C $(LIB_DIR) re
	gcc $(CFLAGS) -I $(INC) -o $(NAME) $(SRCS)

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all
	make -C $(LIB_DIR) re

.PHONY: all clean fclean re
