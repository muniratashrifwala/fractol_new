# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 14:40:20 by mtashrif          #+#    #+#              #
#    Updated: 2024/03/02 17:05:55 by mtashrif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = mouse_events.c keyboard_events.c pixel.c init.c julia.c main.c math_utils.c render.c string_utils.c

OBJ = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re