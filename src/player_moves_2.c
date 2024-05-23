/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:54:48 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/23 10:11:07 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void printf_moves(t_param *param)
{
    mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->wall, 0, 0);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->wall, 34, 0);
	mlx_string_put(param->mlx_ptr, param->mlx_win, 2, 20, 0XFF0000, "Moves : ");
	param->str_moves = ft_itoa(param->p_moves);
	mlx_string_put(param->mlx_ptr, param->mlx_win, 50, 20, 0XFF0000, param->str_moves);
	free(param->str_moves);
}

int check_move(int keycode, t_param *param)
{
    if ((65361 == keycode || 97 == keycode)
		&& (param->map[param->p_y][param->p_x - 1] != '1'
			&& ((param->map[param->p_y][param->p_x - 1] != 'E')
				|| param->coin_c == 0)))
		return (1);
	else if ((65362 == keycode || 119 == keycode) && (param->map[param->p_y
			- 1][param->p_x] != '1' && ((param->map[param->p_y
					- 1][param->p_x] != 'E') || param->coin_c == 0)))
		return (2);
	else if ((65363 == keycode || 100 == keycode)
		&& (param->map[param->p_y][param->p_x + 1] != '1'
			&& ((param->map[param->p_y][param->p_x + 1] != 'E')
				|| param->coin_c == 0)))
		return (3);
	else if ((65364 == keycode || 115 == keycode) && (param->map[param->p_y
			+ 1][param->p_x] != '1' && ((param->map[param->p_y
					+ 1][param->p_x] != 'E') || param->coin_c == 0)))
		return (4);
    return (0);
}
