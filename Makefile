CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/so_long.c  src/put_env.c src/player_moves.c src_gnl/get_next_line.c src_gnl/get_next_line_utils.c \
		src/check_map.c src/map_utils.c src/ft_error.c src/allocation.c src/check_map_2.c src/player_moves_2.c \
		src/some_utils.c src/free_all.c
SRC_B = src_bonus/so_long_bonus.c  src_bonus/put_env_bonus.c src_bonus/player_moves_bonus.c src_gnl/get_next_line.c src_gnl/get_next_line_utils.c \
		src_bonus/check_map_bonus.c src_bonus/map_utils_bonus.c src_bonus/ft_error_bonus.c src_bonus/allocation_bonus.c src_bonus/check_map_2_bonus.c src_bonus/player_moves_2_bonus.c \
		src_bonus/some_utils_bonus.c src_bonus/free_all_bonus.c

SRC_LIBFT = libft
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
NAME = so_long
BONUS = so_long_b
RM = rm -rf

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


all: game $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling src files...⏳"
	@echo "Done✅"
	@echo "Compiling libft src files...⏳"
	@$(MAKE) -C $(SRC_LIBFT) -s
	@echo "Done✅"
	@echo "Linking...⏳"
	@$(CC) $(CFLAGS) $(OBJ) $(SRC_LIBFT)/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Your $(NAME) 🕹️  is ready"

bonus: game $(BONUS)

$(BONUS): $(OBJ_B)
	@echo "Compiling src files...⏳"
	@echo "Done✅"
	@echo "Compiling libft src files...⏳"
	@$(MAKE) -C $(SRC_LIBFT) -s
	@echo "Done✅"
	@echo "Linking...⏳"
	@$(CC) $(CFLAGS) $(OBJ_B) $(SRC_LIBFT)/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS)
	@echo "Your $(NAME) 🕹️  is ready"

clean:
	@echo "Clean .o files...🚮"
	@$(MAKE) clean -C $(SRC_LIBFT) -s
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_B)
	@echo "Done✅"

fclean: clean
	@$(MAKE) fclean -C $(SRC_LIBFT) -s
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	clear
	@echo "Fclean is done✅"

re: fclean all

game:
	@echo "█▀ █▀█ █░░ █▀█ █▄░█ █▀▀"
	@echo "▄█ █▄█ █▄▄ █▄█ █░▀█ █▄█"