/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:16:16 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/23 21:27:14 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_p(int keycode, void *param)
{
	t_param	*param_1;

	param_1 = (t_param *)param;
	if (65307 == keycode)
	{
		mlx_destroy_window(param_1->mlx_ptr, param_1->mlx_win);
		free_all_imgs(param_1);
		exit(0);
	}
	else if (check_move(keycode, param_1) == 1)
		move_left(param_1);
	else if (check_move(keycode, param_1) == 2)
		move_up(param_1);
	else if (check_move(keycode, param_1) == 3)
		move_right(param_1);
	else if (check_move(keycode, param_1) == 4)
		move_down(param);
	if (0 == param_1->coin_c)
	{
		mlx_put_image_to_window(param_1->mlx_ptr, param_1->mlx_win,
			param_1->exit_m, param_1->exit_x * 34, param_1->exit_y * 34);
	}
	return (0);
}

void	move_left(t_param *param)
{
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->player_left,
		(param->p_x - 1) * 34, param->p_y * 34);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->floor,
		param->p_x * 34, param->p_y * 34);
	if (param->map[param->p_y][param->p_x - 1] == 'C')
	{
		param->coin_c--;
		param->map[param->p_y][param->p_x - 1] = '0';
	}
	if (param->map[param->p_y][param->p_x - 1] == 'B')
		game_over(param);
	if (param->map[param->p_y][param->p_x - 1] == 'E' && 0 == param->coin_c)
		you_win(param);
	param->p_x--;
	param->p_moves++;
	printf_moves(param);
}

void	move_up(t_param *param)
{
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->player,
		param->p_x * 34, (param->p_y - 1) * 34);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->floor,
		param->p_x * 34, param->p_y * 34);
	if (param->map[param->p_y - 1][param->p_x] == 'C')
	{
		param->coin_c--;
		param->map[param->p_y - 1][param->p_x] = '0';
	}
	if (param->map[param->p_y - 1][param->p_x] == 'B')
		game_over(param);
	if (param->map[param->p_y - 1][param->p_x] == 'E' && 0 == param->coin_c)
		you_win(param);
	param->p_y--;
	param->p_moves++;
	printf_moves(param);
}

void	move_right(t_param *param)
{
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->player,
		(param->p_x + 1) * 34, param->p_y * 34);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->floor,
		param->p_x * 34, param->p_y * 34);
	if (param->map[param->p_y][param->p_x + 1] == 'C')
	{
		param->coin_c--;
		param->map[param->p_y][param->p_x + 1] = '0';
	}
	if (param->map[param->p_y][param->p_x + 1] == 'B')
		game_over(param);
	if (param->map[param->p_y][param->p_x + 1] == 'E' && 0 == param->coin_c)
		you_win(param);
	param->p_x++;
	param->p_moves++;
	printf_moves(param);
}

void	move_down(t_param *param)
{
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->player,
		param->p_x * 34, (param->p_y + 1) * 34);
	mlx_put_image_to_window(param->mlx_ptr, param->mlx_win, param->floor,
		param->p_x * 34, param->p_y * 34);
	if (param->map[param->p_y + 1][param->p_x] == 'C')
	{
		param->coin_c--;
		param->map[param->p_y + 1][param->p_x] = '0';
	}
	if (param->map[param->p_y][param->p_x + 1] == 'B')
		game_over(param);
	if (param->map[param->p_y + 1][param->p_x] == 'E' && 0 == param->coin_c)
		you_win(param);
	param->p_y++;
	param->p_moves++;
	printf_moves(param);
}