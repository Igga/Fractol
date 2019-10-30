#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 19:57:55 by bmanfrey          #+#    #+#              #
#    Updated: 2019/10/18 19:58:03 by bmanfrey         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRCS = main.c util.c complex.c hooks.c burningship.c julia.c mandelbrot.c other_fractal.c 

OBJ = main.o util.o complex.o hooks.o burningship.o julia.o mandelbrot.o other_fractal.o

CC = gcc

FLAGS = -framework OpenGL -framework AppKit

LIBFT = libft/libft.a 

LIBMLX = minilibx_macos/libmlx.a 

.PHONY = all clean fclean re 

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(FLAGS)

$(OBJ) : $(LIBFT) $(LIBMLX)

%.o:%.c 
	gcc -Wall -Wextra -Werror -O2 -c $< -o $@

$(LIBFT):
	make -C ./libft/

$(LIBMLX):
	make -C ./minilibx_macos/

clean:
	rm -f $(OBJ)
	make clean -C ./libft/
	make clean -C ./minilibx_macos/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
	make fclean -C ./minilibx_macos/

re: fclean all
