# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 00:39:38 by qho               #+#    #+#              #
#    Updated: 2017/04/08 17:08:41 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = ft_contrast

INCLUDES = libft/

SRC = ft_contrast.c

OBJ = ft_contrast.o \

.PHONY: clean fclean re lib all

all: $(NAME)

$(NAME): lib
	@echo "\033[33mCompiling ft_contrast"
	@$(CC) -o $(NAME) $(SRC) -I $(INCLUDES) -L libft/ -lft
	@echo "\033[32mft_contrast made!"

lib:
	@echo "\033[33mRecompiling libft"
	@make -C libft/ fclean && make -C libft/
	
clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
	