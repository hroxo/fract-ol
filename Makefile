# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 20:49:17 by hroxo             #+#    #+#              #
#    Updated: 2025/10/28 21:01:34 by hroxo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
CC=cc
CFLAGS= -Wall -Werror -Wextra
FLAGS_MLX42= -ldl -lglfw -pthread -lm 
#caso isto te estaja a dar errado coloca -lglfw(3)
MLX42=minilibx-linux/libmlx.a
INC= -I src/util.h

SRC= src/main.c
OBJ= $(SRC:.c=.o)

RM= rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) $(MLX42) $(FLAGS_MLX42) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(MLX42) $(FLAGS_MLX42) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
