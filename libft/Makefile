# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tutsumi <tutsumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 00:28:10 by kishigam          #+#    #+#              #
#    Updated: 2025/06/07 10:22:39 by tutsumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_atoi.c ft_putnbr_fd.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

COMPILE = cc $(CFLAGS) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME):
	@$(COMPILE) $(SRC)
	@$(LIB) $(OBJ)
	@$(RANLIB)

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(REMOVE) $(NAME) $(OBJ_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re