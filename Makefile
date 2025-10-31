# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 22:22:06 by hroxo             #+#    #+#              #
#    Updated: 2025/10/31 11:03:17 by hroxo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
CC=cc
CFLAGS= -Wall -Werror -Wextra -O3

LIBFT_DIR=/home/hroxo/lib
LIBFT= $(LIBFT_DIR)/libft.a
FLAGS_MLX42= -ldl -lglfw -pthread -lm -lXext -lX11 -lXrandr -lXi -lXcursor -lXrender -lXfixes
# caso isto te esteja a dar errado coloca -lglfw(3)
MLX42=minilibx-linux/libmlx_Linux.a
INC= -I src

SRC= $(shell find ./src -name "*.c")
OBJ= $(SRC:.c=.o)

RM= rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX42) $(FLAGS_MLX42) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
