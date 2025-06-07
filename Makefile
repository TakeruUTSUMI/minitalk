# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tutsumi <tutsumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 00:28:10 by kishigam          #+#    #+#              #
#    Updated: 2025/06/06 11:03:39 by tutsumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_SERVER = server
NAME_CLIENT = client

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): server.o $(LIBFT)
	@$(CC) -o $@ $< -Llibft -lft

$(NAME_CLIENT): client.o $(LIBFT)
	@$(CC) -o $@ $< -Llibft -lft

bonus: all

%.o: %.c
	@$(CC) -c $(CFLAGS) $<

$(LIBFT):
	@make -s -C libft

clean:
	@rm -f $(OBJS)
	@make -s -C libft clean

fclean: clean
	@rm -f server client libft/libft.a

re: fclean all

.PHONY: $(NAME) all bonus libft clean fclean re
