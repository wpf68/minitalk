# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 09:04:07 by pwolff            #+#    #+#              #
#    Updated: 2022/04/16 09:04:16 by pwolff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

NAME_CLIENT	= client

NAME_SERVER	= server

SRC_CLIENT	= 	srcs/client.c

SRC_SERVER	= 	srcs/server.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

CC		= gcc

FLAGS		= -Wall -Wextra -Werror


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER):	$(SRC_SERVER) $(OBJ_SERVER) maker
	$(CC) $(FLAGS) $(SRC_SERVER) -o $(NAME_SERVER) ./libft_total/libft.a

$(NAME_CLIENT): $(SRC_CLIENT) $(OBJ_CLIENT) maker
	$(CC) $(FLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT) ./libft_total/libft.a


%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

maker:
	make -C ./libft_total

clean:
	make clean -C ./libft_total
	rm -rf $(OBJ_CLIENT) 
	rm -rf $(OBJ_SERVER)

fclean: clean
	make fclean -C ./libft_total
	rm -rf $(NAME_CLIENT)
	rm -rf $(NAME_SERVER)

re: fclean all 

.PHONY:		all clean fclean re
