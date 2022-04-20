# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 00:33:01 by aoukhart          #+#    #+#              #
#    Updated: 2022/02/23 00:42:40 by aoukhart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = src/pipex.c\
		src/utils_1.c\
		src/utils_2.c\
		src/libft_utils.c\
		
CFLAGS = -Wall -Werror -Wextra

OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	@gcc $(CFLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(OBJECT)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all