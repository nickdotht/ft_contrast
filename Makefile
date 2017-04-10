# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 00:39:38 by qho               #+#    #+#              #
#    Updated: 2017/04/09 20:55:31 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_contrast

# Flags and compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Project Source dir, files and headers
INC = ./inc/
SRCDIR = ./src/
SRC = $(shell ls src | grep -E ".+\.c")

# Project Objects dir and files
OBJDIR = ./obj/
OBJS = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# Libft objects and dirs
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/includes

all: $(OBJDIR) $(LIBFT) $(NAME)

# Create the object dir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build the objects
$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(INC) -I$(LIBINC) -o $@ -c $<

# Build the binary file
$(NAME): $(OBJS)
	@echo "\033[33mCompiling ft_contrast"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)
	@echo "\033[32mft_contrast made!"

$(LIBFT):
	@echo "\033[33mRecompiling libft"
	@make -C $(LIBDIR)
	
clean:
	@rm -rf $(OBJDIR) 
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean	

re: fclean all
	
.PHONY: clean fclean re lib all