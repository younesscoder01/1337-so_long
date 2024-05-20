CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = so_long.c src_gnl/get_next_line.c src_gnl/get_next_line_utils.c check_map.c
SRC_LIBFT = libft
OBJ = $(SRC:.c=.o)
NAME = so_long
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C $(SRC_LIBFT) -s
	$(CC) $(CFLAGS) $(OBJ) $(SRC_LIBFT)/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C $(SRC_LIBFT) -s
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(SRC_LIBFT) -s
	$(RM) $(NAME)

re: fclean all