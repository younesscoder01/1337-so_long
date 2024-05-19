/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:20:41 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/19 14:58:52 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	get_map_height(char *path)
{
	int map_fd;
	int map_height;
	char *str;

	map_fd = open(path, O_RDONLY);
	str = get_next_line(map_fd);
	map_height = 0;
	while (str)
	{
		map_height++;
		str = get_next_line(map_fd);
	}
	close(map_fd);
	return map_height;
}

int	get_map_widht(char *str_map)
{
	int map_widht;

	map_widht = 0;
	while (str_map[map_widht])
		map_widht++;
	return (map_widht-1);
}

char **get_map(char *path, char	**map)
{
	int map_fd;
	char *str;
	int i;

	i = 0;
	map_fd = open(path, O_RDONLY);
	str = get_next_line(map_fd);
	map[i++] = str;
	while (str)
	{
		str = get_next_line(map_fd);
		map[i++] = str;
	}
	map[i++] = NULL;
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	close(map_fd);
	return map;
}


void put_env(char **map, void	*mlx_ptr, void	*mlx_win, t_param *imgs)
{
	int x;
	int y;

	y = 0;
	x = 0;
	imgs->coin_c = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, mlx_win, imgs->wall, x * 34, y * 34);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx_ptr, mlx_win, imgs->floor, x * 34, y * 34);
			else if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx_ptr, mlx_win, imgs->collectible, x * 34, y * 34);
				imgs->coin_c++;
			}
			else if (map[y][x] == 'P')
			{
				mlx_put_image_to_window(mlx_ptr, mlx_win, imgs->player, x * 34, y * 34);
				imgs->p_x = x;
				imgs->p_y = y;
			}
			else if (map[y][x] == 'E')
			{
				mlx_put_image_to_window(mlx_ptr, mlx_win, imgs->exit, x * 34, y * 34);
				imgs->exit_x = x;
				imgs->exit_y = y;
			}
			x++;
		}
		y++;
	}
	printf("==> %i\n", imgs->coin_c);
}



int key_p(int keycode, void *param)
{
	t_param *param_1;

	param_1 = (t_param *)param;
	if (65307 == keycode)
	{
		mlx_destroy_window(param_1->mlx_ptr, param_1->mlx_win);
		exit(0);
	}
	else if ((65361 == keycode || 97 == keycode) && param_1->map[param_1->p_y][param_1->p_x-1] != '1')
	{
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->player, (param_1->p_x-1) * 34, param_1->p_y * 34);
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->floor, param_1->p_x * 34, param_1->p_y * 34);
		if (param_1->map[param_1->p_y][param_1->p_x-1] == 'C')
		{
			param_1->coin_c--;
			param_1->map[param_1->p_y][param_1->p_x-1] = '0';
		}
		if (param_1->map[param_1->p_y][param_1->p_x-1] == 'E' && 0 == param_1->coin_c)
		{
			mlx_destroy_window(param_1->mlx_ptr, param_1->mlx_win);
			exit(0);
		}
		param_1->p_x--;
	}
	else if ((65362 == keycode || 119 == keycode) && param_1->map[param_1->p_y-1][param_1->p_x] != '1')
	{
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->player, param_1->p_x * 34, (param_1->p_y-1) * 34);
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->floor, param_1->p_x * 34, param_1->p_y * 34);
		if (param_1->map[param_1->p_y-1][param_1->p_x] == 'C')
		{
			param_1->coin_c--;
			param_1->map[param_1->p_y-1][param_1->p_x] = '0';
		}
		if (param_1->map[param_1->p_y-1][param_1->p_x] == 'E' && 0 == param_1->coin_c)
		{
			mlx_destroy_window(param_1->mlx_ptr, param_1->mlx_win);
			exit(0);
		}
		param_1->p_y--;
	}
	else if ((65363 == keycode || 100 == keycode) && param_1->map[param_1->p_y][param_1->p_x+1] != '1')
	{
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->player, (param_1->p_x+1) * 34, param_1->p_y * 34);
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->floor, param_1->p_x * 34, param_1->p_y * 34);
		if (param_1->map[param_1->p_y][param_1->p_x+1] == 'C')
		{
			param_1->coin_c--;
			param_1->map[param_1->p_y][param_1->p_x+1] = '0';
		}
		if (param_1->map[param_1->p_y][param_1->p_x+1] == 'E' && 0 == param_1->coin_c)
		{
			mlx_destroy_window(param_1->mlx_ptr, param_1->mlx_win);
			exit(0);
		}
		param_1->p_x++;
	}
	else if ((65364 == keycode || 115 == keycode) && param_1->map[param_1->p_y+1][param_1->p_x] != '1')
	{
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->player, param_1->p_x * 34, (param_1->p_y+1) * 34);
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->floor, param_1->p_x * 34, param_1->p_y * 34);
		if (param_1->map[param_1->p_y+1][param_1->p_x] == 'C')
		{
			param_1->coin_c--;
			param_1->map[param_1->p_y+1][param_1->p_x] = '0';
		}
		if (param_1->map[param_1->p_y+1][param_1->p_x] == 'E' && 0 == param_1->coin_c)
		{
			mlx_destroy_window(param_1->mlx_ptr, param_1->mlx_win);
			exit(0);
		}	
		param_1->p_y++;
	}
	if (0 == param_1->coin_c)
	{
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win, param_1->exit_m, param_1->exit_x * 34, param_1->exit_y * 34);
	}
		
	printf("%i\n", keycode);
	printf("===>%i\n", param_1->coin_c);
	return 0;	
}



int	main(int argc, char *argv[])
{
	char	**map;
	int map_height;
	int map_widht;
	t_param	param;
	int		widht;
	int		height;

	if (argc != 2)
		return (1);
	check_file();
	widht = 34;
	height = 34;
	if (argc < 2)
		return (1);
	map_height = get_map_height(argv[1]);
	map = malloc(sizeof(char *) * map_height + 1);
	map = get_map(argv[1], map);
	param.map =	map;
	map_widht = get_map_widht(map[0]);
	printf("h = %d  w = %d\n", map_height, map_widht);
	param.mlx_ptr = mlx_init();
	param.mlx_win = mlx_new_window(param.mlx_ptr, map_widht * 34, map_height * 34, "test_1");
	param.wall = mlx_xpm_file_to_image(param.mlx_ptr, "textures/wall_v2.xpm", &widht, &height);
	param.floor = mlx_xpm_file_to_image(param.mlx_ptr, "textures/floor_v2.xpm", &widht, &height);
	param.collectible = mlx_xpm_file_to_image(param.mlx_ptr, "textures/coin.xpm", &widht, &height);
	param.player = mlx_xpm_file_to_image(param.mlx_ptr, "textures/kinght_v2.xpm", &widht, &height);
	param.exit = mlx_xpm_file_to_image(param.mlx_ptr, "textures/portal_f0.xpm", &widht, &height);
	param.exit_m = mlx_xpm_file_to_image(param.mlx_ptr, "textures/portal_f1.xpm", &widht, &height);
	put_env(map, param.mlx_ptr, param.mlx_win, &param);
	mlx_hook(param.mlx_win, 2, 1L<<0, key_p, &param);
	mlx_loop(param.mlx_ptr);
}


