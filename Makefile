# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrameau <jrameau@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 00:39:38 by qho               #+#    #+#              #
#    Updated: 2017/04/09 22:24:06 by jrameau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = ft_contrast
NAME2 = ft_contrast_th

# Flags and compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Project Source dir, files and headers
INC = ./inc/
SRCDIR1 = ./src1/
SRCDIR2 = ./src2/
SRC1 = $(shell ls src1 | grep -E ".+\.c")
SRC2 = $(shell ls src2 | grep -E ".+\.c")

# Project Objects dir and files
OBJDIR1 = ./obj1/
OBJDIR2 = ./obj2/
OBJS1 = $(addprefix $(OBJDIR1), $(SRC1:.c=.o))
OBJS2 = $(addprefix $(OBJDIR2), $(SRC2:.c=.o))

# Libft objects and dirs
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/includes

all: $(OBJDIR1) $(OBJDIR2) $(LIBFT) $(NAME1) $(NAME2)

# Create the object dir 1
$(OBJDIR1):
	mkdir -p $(OBJDIR1)

# Create the object dir 2
$(OBJDIR2):
	mkdir -p $(OBJDIR2)

# Build the objects 1
$(OBJDIR1)%.o:$(SRCDIR1)%.c
	$(CC) $(CFLAGS) -I$(INC) -I$(LIBINC) -o $@ -c $<

# Build the objects 2
$(OBJDIR2)%.o:$(SRCDIR2)%.c
	$(CC) -g $(CFLAGS) -I$(INC) -I$(LIBINC) -o $@ -c $<

# Build the binary file 1
$(NAME1): $(OBJS1)
	@echo "\033[33mCompiling ft_contrast"
	@$(CC) -o $(NAME1) $(CFLAGS) $(OBJS1) $(LIBFT)
	@echo "\033[32mft_contrast made!"

# Build the binary file 2
$(NAME2): $(OBJS2)
	@echo "\033[33mCompiling ft_contrast_th"
	@$(CC) -o $(NAME2) $(CFLAGS) $(OBJS2) $(LIBFT)
	@echo "\033[32mft_contrast_th made!"

$(LIBFT):
	@echo "\033[33mRecompiling libft"
	@make -C $(LIBDIR)
	
clean:
	@rm -rf $(OBJDIR1) 
	@rm -rf $(OBJDIR2) 
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make -C $(LIBDIR) fclean	

re: fclean all
	
.PHONY: clean fclean re lib all