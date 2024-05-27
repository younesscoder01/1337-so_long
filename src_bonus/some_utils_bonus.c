/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:31:42 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/27 13:27:54 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	close_win(t_param *param)
{
	mlx_destroy_window(param->mlx_ptr, param->mlx_win);
	free_all_imgs(param);
	exit(0);
}

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
