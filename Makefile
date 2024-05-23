CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = src/so_long.c  src/put_env.c src/player_moves.c src_gnl/get_next_line.c src_gnl/get_next_line_utils.c \
		src/check_map.c src/map_utils.c src/ft_error.c src/allocation.c src/check_map_2.c src/player_moves_2.c \

SRC_LIBFT = libft
OBJ = $(SRC:.c=.o)
NAME = so_long
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


clean:
	@echo "Clean .o files...🚮"
	@$(MAKE) clean -C $(SRC_LIBFT) -s
	@$(RM) $(OBJ)
	@echo "Done✅"

fclean: clean
	@$(MAKE) fclean -C $(SRC_LIBFT) -s
	@$(RM) $(NAME)
	clear
	@echo "Fclean is done✅"

re: fclean all

game:
	@echo "█▀ █▀█ █░░ █▀█ █▄░█ █▀▀"
	@echo "▄█ █▄█ █▄▄ █▄█ █░▀█ █▄█"