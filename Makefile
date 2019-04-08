# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angkim <angkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 09:30:19 by angkim            #+#    #+#              #
#    Updated: 2019/04/07 16:07:59 by angkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
 
CFLAGS = -Wall -Werror -Wextra

INCLUDES = 

SRCS = 

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS) -I $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
