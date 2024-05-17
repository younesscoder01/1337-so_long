CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c src_gnl/get_next_line.c src_gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
NAME = so_long
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean	
	$(RM) $(NAME)

re: all fclean