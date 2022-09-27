# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 21:11:15 by vly               #+#    #+#              #
#    Updated: 2022/09/26 20:33:37 by vly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		server.c
			client.c
CC =		gcc
CFLAGS =	-Werror -Wextra -Wall			
INC =		libft/libft.a

all: $(NAME)

$(NAME):
			@make -C libft
			$(CC) $(CFLAGS) -o server server.c
			$(CC) $(CFLAGS) -o client client.c

clean:
			@make clean -C libft
			rm -f server client

fclean:
			@make fclean -C libft
			rm -f server client

re:			fclean all

.PHONY: 	re all clean fclean