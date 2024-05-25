/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:15:09 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/25 16:37:58 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	check_exit(char **map_flood, t_param *param)
{
	if (map_flood[param->e_y][param->e_x + 1] == 'G'
		|| map_flood[param->e_y][param->e_x - 1] == 'G')
		return (0);
	else if (map_flood[param->e_y + 1][param->e_x] == 'G'
		|| map_flood[param->e_y - 1][param->e_x] == 'G')
		return (0);
	return (1);
}

int	no_other_char(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'E'
				&& map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != 'B')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	only_allowed(char **map)
{
	int	x;
	int	y;
	t_allowed allowed;
	allowed.c = 0;
	allowed.e = 0;
	allowed.p = 0;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				allowed.e++;
			if (map[y][x] == 'C')
				allowed.c++;
			if (map[y][x] == 'P')
				allowed.p++;
			x++;
		}
		y++;
	}
	if (allowed.c >= 1 && allowed.e == 1 && allowed.p == 1)
		return (0);
	return (1);
}

int	ft_strlen_map(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int	check_len(char **map)
{
	int	len;
	int	y;

	len = ft_strlen_map(map[0]);
	y = 0;
	while (map[y])
	{
		if (len != ft_strlen_map(map[y]))
			return (1);
		y++;
	}
	return (0);
}

void	check_flood_fill(t_param *param, char *path)
{
	char	**map_flood;

	map_flood = malloc(sizeof(char *) * (param->map_height + 1));
	get_map(path, map_flood);
	get_p_xy(map_flood, param);
	flood_fill(map_flood, param->p_x, param->p_y, param);
	if (check_f(map_flood) || check_exit(map_flood, param))
	{
		ft_free(map_flood);
		ft_free(param->map);
		free(param);
		write(2, "Error\n", 6);
		exit(12);
	}
	ft_free(map_flood);
}
