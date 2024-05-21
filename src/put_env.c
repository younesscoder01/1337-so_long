/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:16:00 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/21 15:32:08 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_player(void *mlx_ptr, void *mlx_win, t_env *env)
{
	mlx_put_image_to_window(mlx_ptr, mlx_win, env->imgs->player, env->x * 34,
		env->y * 34);
	env->imgs->p_x = env->x;
	env->imgs->p_y = env->y;
}

void	put_exit(void *mlx_ptr, void *mlx_win, t_env *env)
{
	mlx_put_image_to_window(mlx_ptr, mlx_win, env->imgs->exit, env->x * 34,
		env->y * 34);
	env->imgs->exit_x = env->x;
	env->imgs->exit_y = env->y;
}

void	put_coin(void *mlx_ptr, void *mlx_win, t_env *env)
{
	mlx_put_image_to_window(mlx_ptr, mlx_win, env->imgs->collectible, env->x
		* 34, env->y * 34);
	env->imgs->coin_c++;
}

void	check_and_put(char **map, void *mlx_ptr, void *mlx_win, t_env *env)
{
	if (map[env->y][env->x] == '1')
		mlx_put_image_to_window(mlx_ptr, mlx_win, env->imgs->wall, env->x * 34,
			env->y * 34);
	else if (map[env->y][env->x] == '0')
		mlx_put_image_to_window(mlx_ptr, mlx_win, env->imgs->floor, env->x * 34,
			env->y * 34);
	else if (map[env->y][env->x] == 'C')
		put_coin(mlx_ptr, mlx_win, env);
	else if (map[env->y][env->x] == 'P')
		put_player(mlx_ptr, mlx_win, env);
	else if (map[env->y][env->x] == 'E')
		put_exit(mlx_ptr, mlx_win, env);
}

void	put_env(void *mlx_ptr, void *mlx_win, t_param *imgs)
{
	t_env	env;

	env.y = 0;
	imgs->coin_c = 0;
	env.imgs = imgs;
	while (imgs->map[env.y])
	{
		env.x = 0;
		while (imgs->map[env.y][env.x])
		{
			check_and_put(imgs->map, mlx_ptr, mlx_win, &env);
			env.x++;
		}
		env.y++;
	}
}
