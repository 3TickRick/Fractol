# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbrune <rbrune@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/17 11:14:11 by rbrune        #+#    #+#                  #
#    Updated: 2022/05/30 17:23:52 by rbrune        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


# Compiler and flags
CC = gcc 
CFLAGS  = -g3 -Werror -Wall -Wextra

# exe name
NAME = fractol

# C Files
SRC = main.c fractals.c colors.c input.c
# OBJect files
OBJ = $(SRC:.c=.o)

# Library's
HEADERS			= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBFT			= ./lib/libft
LIBMLX			= ./lib/MLX42
LIBS			= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a

all : libft libmlx $(NAME)
	
libft:
	@$(MAKE) -s -C $(LIBFT)

libmlx:
	@$(MAKE) -s -C $(LIBMLX)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(LIBMLX) clean
	rm -f $(OBJ)

fclean:
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(LIBMLX) fclean
	rm -f $(NAME) $(OBJ) 

re: fclean all

.PHONY: clean fclean all re