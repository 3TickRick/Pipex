# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbrune <rbrune@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/08 11:17:29 by rbrune        #+#    #+#                  #
#    Updated: 2022/04/20 15:12:33 by rbrune        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc 
CFLAGS  = -Werror -Wall -Wextra
NAME = libft.a

src = ft_putstr.c ft_putchar.c ft_putnbr.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_itoa.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strnstr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_memcmp.c ft_memchr.c ft_calloc.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c
obj = ft_putstr.o ft_putchar.o ft_putnbr.o ft_itoa.o ft_striteri.o ft_strmapi.o ft_split.o ft_putnbr_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_itoa.o ft_strtrim.o ft_strjoin.o ft_substr.o ft_strnstr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_memcmp.o ft_memchr.o ft_calloc.o ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memcpy.o ft_memmove.o ft_memset.o ft_strchr.o ft_strlen.o ft_strncmp.o ft_strrchr.o ft_tolower.o ft_toupper.o ft_lstmap_bonus.o ft_lstiter_bonus.o ft_lstclear_bonus.o ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o	ft_lstadd_back_bonus.o ft_lstdelone_bonus.o


all : $(NAME)

$(NAME) : $(obj)
	@ar -rsc $(NAME) $(obj) 

clean:
	rm -f $(obj) $(objbonus)

fclean:
	rm -f $(NAME) $(obj) $(objbonus)

re: fclean all

.PHONY: clean fclean bonus all re