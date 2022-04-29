# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmichel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 13:17:34 by lmichel           #+#    #+#              #
#    Updated: 2021/11/21 13:52:45 by lmichel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= get_next_line.c get_next_line_utils.c so_long.c main.c ft_split.c ft_putstr_fd.c ft_itoa.c ft_strjoin.c so_long_utils.c main_utils.c

OBJS	= $(SRCS:.c=.o)

HEADER	= so_long.h

CFLAGS	= -Wall -Wextra -Werror -I $(HEADER)

MLX		= mlx/libmlx.a

LIBS	= -L mlx -lmlx -framework OpenGL -framework AppKit

CC		= gcc

.PHONY: all clean fclean re

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(MLX) $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $@

$(MLX):
	make -C mlx

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all