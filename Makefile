# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Source files and object files
SRCS = main.c $(SRC_DIR)/move.c $(SRC_DIR)/map_validating.c \
       $(SRC_DIR)/render.c $(SRC_DIR)/read_map.c $(SRC_DIR)/utils.c \
       $(SRC_DIR)/texture.c $(SRC_DIR)/handalers.c $(SRC_DIR)/libft_functions.c \
	   $(SRC_DIR)/valid_map.c $(SRC_DIR)/wall_check.c \
	   get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable
NAME = so_long

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lmlx -lX11 -lXext

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
