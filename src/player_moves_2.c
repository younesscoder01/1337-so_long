/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:54:48 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/27 14:41:12 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	printf_moves(t_param *param)
{
	param->str_moves = ft_itoa(param->p_moves);
	write(1, "Moves : ", 8);
	write(1, param->str_moves, ft_strlen(param->str_moves));
	free(param->str_moves);
	write(1, "\n", 1);
}

int	check_move(int keycode, t_param *param)
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

void	you_win(t_param *param)
{
	mlx_destroy_window(param->mlx_ptr, param->mlx_win);
	param->p_moves++;
	printf_moves(param);
	free_all_imgs(param);
	write(1, "You Win\n", 8);
	exit(0);
}
