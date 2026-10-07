# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/07 20:05:11 by lsallam           #+#    #+#              #
#    Updated: 2026/10/07 20:05:16 by lsallam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_char.c ft_hex.c ft_int.c ft_printf.c ft_ptr.c ft_string.c ft_unsigned.c  ft_itoa.c ft_strlen.c ft_memcpy.c

OBJ = $(SRC:.c=.o)

all :$(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re