/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:09:13 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/25 14:29:22 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all_imgs(t_param *param)
{
	if (param->wall)
		mlx_destroy_image(param->mlx_ptr, param->wall);
	if (param->floor)
		mlx_destroy_image(param->mlx_ptr, param->floor);
	if (param->exit)
		mlx_destroy_image(param->mlx_ptr, param->exit);
	if (param->exit_m)
		mlx_destroy_image(param->mlx_ptr, param->exit_m);
	if (param->collectible)
		mlx_destroy_image(param->mlx_ptr, param->collectible);
	if (param->player)
		mlx_destroy_image(param->mlx_ptr, param->player);
	if (param->player_left)
		mlx_destroy_image(param->mlx_ptr, param->player_left);
	if (param->bat)
		mlx_destroy_image(param->mlx_ptr, param->bat);
	if (param->mlx_ptr)
	{
		mlx_destroy_display(param->mlx_ptr);
		free(param->mlx_ptr);
	}
	ft_free(param->map);
	free(param);
}
