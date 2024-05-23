/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:20:50 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/23 10:31:41 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../src_gnl/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>
typedef struct	s_param {
	int map_height;
	int map_widht;
	int		img_widht;
	int		img_height;
	void	*wall;
	void	*player;
	void	*player_left;
	int		p_moves;
	void	*collectible;
	void	*floor;
	void	*exit;
	void	*exit_m;
	void	*mlx_ptr;
	void	*mlx_win;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		exit_x;
	int		exit_y;
	char	**map;
	int		coin_c;
	char	*str_moves;
}				t_param;

typedef struct	s_env {
	int		x;
	int		y;
	t_param	*imgs;
}				t_env;

int check_file(char *file_name);
int cheack_wall(char **map, int map_height, int map_widht);
void flood_fill(char **map, int x, int y, int map_height, int map_widht);
int check_f(char **map);
void get_p_xy(char **map, t_param *data);


void put_env(void	*mlx_ptr, void	*mlx_win, t_param *imgs);

int key_p(int keycode, void *param);
void move_left(t_param *param);
void move_up(t_param *param);
void move_right(t_param *param);
void move_down(t_param *param);


int	get_map_height(char *path);
int	get_map_widht(char *str_map);
void get_map(char *path, char	**map);

void ft_error_exit(void);
void free_all_imgs(t_param *param);
void ft_error_wall(t_param *param);

void allocation(t_param	*param);

void check_flood_fill(t_param	*param, char *argv);
void	ft_free(char **arr);

void printf_moves(t_param *param);
int check_move(int keycode, t_param *param);
#endif