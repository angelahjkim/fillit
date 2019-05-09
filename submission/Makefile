# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angkim <angkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 09:30:19 by angkim            #+#    #+#              #
#    Updated: 2019/05/08 18:59:30 by angkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	libft/libft.a \
		srcs/main.c \
		srcs/read.c \
		srcs/check.c \
		srcs/create.c \
		srcs/solve.c \
		srcs/free.c

OBJS = $(SRCS:%.c=%.o)

INC = ./incs 

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

.PHONY: all clean fclean re
