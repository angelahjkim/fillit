# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angkim <angkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 09:30:19 by angkim            #+#    #+#              #
#    Updated: 2019/04/22 12:20:00 by angkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
 
CFLAGS = -Wall -Werror -Wextra -I ./includes/ -o

LIB = libft/

COMPL = make -C $(LIB) re

COMPLC = make -C $(LIB) clean

COMPLF = make -C $(LIB) fclean

SRC = src/

SRCS =  $(LIB)libft.a \
		$(SRC)main.c \
		$(SRC)read.c

# OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	
	gcc $(CFLAGS) $(NAME) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
