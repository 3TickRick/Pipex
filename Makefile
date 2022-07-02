# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbrune <rbrune@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/17 11:14:11 by rbrune        #+#    #+#                  #
#    Updated: 2022/05/12 12:45:05 by rbrune        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


# Compiler and flags
CC = gcc 
CFLAGS  = -Werror -Wall -Wextra

# exe name
NAME = pipex

# C Files
SRC = main.c error.c child.c
# Object files
OBJ = $(SRC:.c=.o)

# Self made library
LIB				= ./libft/libft.a
LIBFT_LOC		= libft
LIBFT_LIB		= libft/libft.a



all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -s -C $(LIBFT_LOC)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	@$(MAKE) -s -C $(dir $(LIB)) clean
	rm -f $(OBJ)

fclean:
	@$(MAKE) -s -C $(dir $(LIB)) fclean
	rm -f $(NAME) $(OBJ) 

re: fclean
	$(MAKE) all

.PHONY: clean fclean all re