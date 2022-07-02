# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbrune <rbrune@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/08 11:17:29 by rbrune        #+#    #+#                  #
#    Updated: 2022/05/12 15:41:46 by rbrune        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc 
CFLAGS  = -Werror -Wall -Wextra
NAME = libft.a

SRC = ft_putstr.c ft_putchar.c  ft_strcmp.c ft_strlowcase.c ft_putnbr.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_itoa.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strnstr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_memcmp.c ft_memchr.c ft_calloc.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rsc $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: clean fclean all re