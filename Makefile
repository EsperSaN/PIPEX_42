# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 14:42:41 by pruenrua          #+#    #+#              #
#    Updated: 2023/05/26 19:49:40 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex

SRC = runcmd.c error.c pipework.c get_next_line_utils.c get_next_line.c pipex_tool.c help.c help2.c free.c doctype.c pipex.c

SRC_B = runcmd.c error.c pipework.c get_next_line_utils.c get_next_line.c pipex_tool.c help.c help2.c free.c pipex.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra# -fsanitize=address -g

OBJ = $(SRC:.c=.o)

BOBJ = $(SRC:.c=.o)

all : $(NAME) clean

bonus : $(BOBJ)
	$(CC) $(BOBJ) -o $(NAME_BONUS)

$(NAME) : $(OBJ)
	 $(CC) $(OBJ) -o $(NAME)
clean :
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)
	
re : fclean $(NAME)

.PHONY : clean fclean re all