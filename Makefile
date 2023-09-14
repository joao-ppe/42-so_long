# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 15:07:56 by joao-ppe          #+#    #+#              #
#    Updated: 2023/09/14 15:15:59 by joao-ppe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f

NAME = so_long
NAME_BNS = so_long_bonus

SRC =	src/main.c \
	src/init.c \
	src/map_check_a.c \
	src/map_check_b.c \
	src/map_utils.c \
	src/map_check_utils.c \
	src/free_utils.c \
	src/render_window.c \
	src/render_map.c \
	src/movement.c \
	src/movement_utils.c \

SRC_BNS = 	src_bonus/main_bonus.c \
           	src_bonus/init_bonus.c \
         	src_bonus/map_check_a_bonus.c \
           	src_bonus/map_check_b_bonus.c \
           	src_bonus/map_utils_bonus.c \
           	src_bonus/map_check_utils_bonus.c \
			src_bonus/game_check_bonus.c \
           	src_bonus/free_utils_bonus.c \
           	src_bonus/render_window_bonus.c \
           	src_bonus/render_map_bonus.c \
           	src_bonus/p_movement_lvl1_bonus.c \
			src_bonus/p_movement_lvl2_bonus.c \
           	src_bonus/p_movement_utils_bonus.c \
			src_bonus/p_anims_utils_bonus.c \
			src_bonus/p_anims_bonus.c \
			src_bonus/e_movement_bonus.c \
			src_bonus/e_movement_utils_bonus.c \
			src_bonus/e_utils_bonus.c \
			src_bonus/e_anims_extra_bonus.c \
			src_bonus/map_anims_bonus.c \
			src_bonus/hud_bonus.c \
			
OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)

deps: 
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx-linux

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: deps $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BNS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BNS)

clean: 
	$(MAKE) clean -C ./libs/libft
	$(MAKE) clean -C ./libs/minilibx-linux
	@$(RM) $(OBJ) $(OBJ_BNS)

fclean : clean
	@$(RM) $(LIBFT) $(NAME) $(NAME_BNS)

download:
	@wget https://cdn.intra.42.fr/document/document/20776/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C libs
	@rm minilibx-linux.tgz

re: fclean all bonus