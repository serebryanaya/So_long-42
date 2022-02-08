NAME_O 				= so_long
NAME_B 				= bonus
NAME				= so_long

FLAGS 				= -Wall -Wextra -Werror -O2
LIB_DIR 			= mlx

SRC_O_DIR			= src/mandatory/
SRC_B_DIR			= src/bonus/
SRC_O 				= animation.c \
					buttons.c \
					check_map.c \
					create_and_exit.c \
					gnl_utils.c \
					gnl.c \
					moving.c \
					so_long_main.c \
					standart.c \
					textures.c \
					textures2.c \
					utils.c

SRC_B 				= animation_bonus.c \
					buttons_bonus.c \
					check_map_bonus.c \
					create_and_exit_bonus.c \
					gnl_utils_bonus.c \
					gnl_bonus.c \
					moving_bonus.c \
					so_long_main_bonus.c \
					standart_bonus.c \
					textures_bonus.c \
					textures2_bonus.c \
					utils_bonus.c

HEAD_DIR 			= inc/
HEAD_O 				= so_long.h
HEAD_B 				= so_long_bonus.h

OBJ_O				= $(patsubst %.c,%.o,$(SRC_O))
OBJ_B				= $(patsubst %.c,%.o,$(SRC_B))
OBJ_DIR				= obj/
OBJ_O_DIR			= obj/mandatory/
OBJ_B_DIR			= obj/bonus/

OBJS_1 				= $(addprefix $(OBJ_O_DIR), $(OBJ_O))
OBJS_2 				= $(addprefix $(OBJ_B_DIR), $(OBJ_B))

CC 					= gcc
RM 					= rm -f

MLX_FLAGS			= -framework OpenGL -framework AppKit

all: 				$(NAME)

bonus:				$(NAME)

$(OBJ_O_DIR)%.o: 	$(SRC_O_DIR)%.c $(HEAD_DIR)$(HEAD_O) Makefile
					@mkdir -p $(OBJ_O_DIR)
					@gcc -c $< -o $@ -I $(HEAD_DIR)

$(OBJ_B_DIR)%.o: 	$(SRC_B_DIR)%.c $(HEAD_DIR)$(HEAD_B) Makefile
					@mkdir -p $(OBJ_B_DIR)
					@gcc -c $< -o $@ -I $(HEAD_DIR)

$(NAME):  			$(OBJS_1) $(OBJS_2) $(LIB_DIR)/*
					@make -C $(LIB_DIR)
					@ln -f $(LIB_DIR)/libmlx.dylib libmlx.dylib
					$(CC) $(FLAGS) $(OBJS_1) -lmlx $(MLX_FLAGS) -L $(LIB_DIR) -o $(NAME_O)
					$(CC) $(FLAGS) $(OBJS_2) -lmlx $(MLX_FLAGS) -L $(LIB_DIR) -o $(NAME_B)

FRAMEWORKS 			= -framework OpenGL -framework AppKit

clean:
					@make clean -C $(LIB_DIR)
					@rm -Rf $(OBJ_DIR)
					@rm libmlx.dylib

fclean: 			clean
					@make clean -C $(LIB_DIR)
					@rm -f $(NAME_O) $(NAME_B)

re: 				fclean all

.PHONY: 			all bonus clean fclean re