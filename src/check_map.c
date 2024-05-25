/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:05:46 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/25 17:57:19 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file(char *file_name)
{
	int	len;
	int	c;

	len = ft_strlen(file_name) - 1;
	c = 0;
	if ('r' == file_name[len--])
		c++;
	if ('e' == file_name[len--])
		c++;
	if ('b' == file_name[len--])
		c++;
	if ('.' == file_name[len--])
		c++;
	if (c == 4)
		return (1);
	return (0);
}

int	cheack_wall(char **map, int map_height, int map_widht)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_height)
	{
		if (map[i][0] != '1')
			break ;
		if (map[i][map_widht - 1] != '1')
			break ;
		i++;
	}
	while (j < map_widht)
	{
		if (map[0][j] != '1')
			break ;
		if (map[map_height - 1][j] != '1')
			break ;
		j++;
	}
	if (i != map_height || j != map_widht || no_other_char(map) || only_allowed(map))
		return (0);
	return (1);
}

void	flood_fill(char **map, int x, int y, t_param *param)
{
	if (x < 0 || y < 0 || x >= param->map_widht || y >= param->map_height)
		return ;
	if ('1' == map[y][x] || map[y][x] == 'G' || map[y][x] == 'E'
		|| 'B' == map[y][x])
		return ;
	map[y][x] = 'G';
	flood_fill(map, x + 1, y, param);
	flood_fill(map, x - 1, y, param);
	flood_fill(map, x, y + 1, param);
	flood_fill(map, x, y - 1, param);
}

int	check_f(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P' || map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	get_p_xy(char **map, t_param *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			if (map[y][x] == 'E')
			{
				data->e_x = x;
				data->e_y = y;
			}
			x++;
		}
		y++;
	}
}
