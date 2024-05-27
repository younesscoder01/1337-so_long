/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:31:42 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/27 13:15:01 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(t_param *param)
{
	mlx_destroy_window(param->mlx_ptr, param->mlx_win);
	free_all_imgs(param);
	exit(0);
}

int	only_allowed(char **map)
{
	t_allowed	allowed;

	allowed.c = 0;
	allowed.e = 0;
	allowed.p = 0;
	allowed.y = 0;
	while (map[allowed.y])
	{
		allowed.x = 0;
		while (map[allowed.y][allowed.x])
		{
			if (map[allowed.y][allowed.x] == 'E')
				allowed.e++;
			if (map[allowed.y][allowed.x] == 'C')
				allowed.c++;
			if (map[allowed.y][allowed.x] == 'P')
				allowed.p++;
			allowed.x++;
		}
		allowed.y++;
	}
	if (allowed.c >= 1 && allowed.e == 1 && allowed.p == 1)
		return (0);
	return (1);
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
