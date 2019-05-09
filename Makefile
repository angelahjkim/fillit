# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angkim <angkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 09:30:19 by angkim            #+#    #+#              #
#    Updated: 2019/05/09 10:39:45 by angkim           ###   ########.fr        #
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
	@echo "\x1b[32mmaking libft library..."
	@make -C $(LIB_DIR) re
	@echo "\x1b[32mcompiling and making fillit executable...\x1b[0m"
	@gcc $(CFLAGS) -I $(INC) -o $(NAME) $(SRCS)

clean:
	@echo "\x1b[33mcleaning libft..."
	@make -C $(LIB_DIR) clean
	@echo "\x1b[33mcleaning fillit...\x1b[0m"
	@rm -f $(OBJS)

fclean: clean
	@echo "\x1b[33mremoving libft..."
	@make -C $(LIB_DIR) fclean
	@echo "\x1b[33mremoving fillit executable...\x1b[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
