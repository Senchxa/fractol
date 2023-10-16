# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnoll <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 15:30:35 by dnoll             #+#    #+#              #
#    Updated: 2023/10/15 17:09:29 by dnoll            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Compiler and flags

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC = main.c start.c render.c utils.c utils2.c events.c hooks.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean :
	@rm -rf $(NAME)




