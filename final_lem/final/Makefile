# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlibago <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/28 12:14:16 by hlibago           #+#    #+#              #
#    Updated: 2018/04/28 13:56:05 by hlibago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c algorithm.c  move_ants.c rooms.c free.c check_char.c \
	  read_map.c \

FLAG = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME):
		@make -C libft $(SILENT)
		@gcc $(FLAG) -c $(SRC)
		@gcc $(FLAG) $(OBJ)  libft/libft.a -lreadline -o $(NAME)

clean:
		@make clean -C libft $(SILENT)
		@/bin/rm -f $(OBJ) $(LOBJ) *.o

fclean: clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft $(SILENT)

re: fclean all


