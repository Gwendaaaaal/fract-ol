# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 21:58:52 by gholloco          #+#    #+#              #
#    Updated: 2024/04/11 13:50:29 by gholloco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src

SOURCES = draw.c event_handlers.c free.c init.c main.c parse.c utils.c 

OBJ_DIR = obj

OBJECT = $(SOURCES:.c=.o)

OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJECT))

LIBFT_DIR = ./includes/Libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./includes/minilibx-linux

MLX = $(MLX_DIR)/libmlx.a

CC = cc

CFLAGS = -g

MLX_FLAGS = -lmlx -lXext -lX11

RMFLAGS = -rf

all : $(OBJ_DIR) $(NAME)

bonus : $(OBJ_DIR) $(CHECKER)

$(NAME) : $(OBJECTS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -L$(MLX_DIR) $^ $(MLX_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(LIBFT) :  
	make -C $(LIBFT_DIR) bonus

$(MLX) :
	make -C $(MLX_DIR) 

clean :
	rm $(RMFLAGS) $(OBJECTS) $(OBJECTS_CHECKER)
	make -C $(LIBFT_DIR) clean 
	make -C $(MLX_DIR) clean 

fclean : clean
	rm $(RMFLAGS) $(NAME) $(CHECKER)
	make -C $(LIBFT_DIR) fclean

re : fclean all

PHONY = all clean fclean re

