/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:45 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/21 15:01:25 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void allocation(t_param	*param)
{
    param->mlx_ptr = mlx_init();
	param->mlx_win = mlx_new_window(param->mlx_ptr, param->map_widht * 34, param->map_height * 34, "test_1");
	param->wall = mlx_xpm_file_to_image(param->mlx_ptr, "textures/wall_v2.xpm", &param->img_widht, &param->img_height);
	param->floor = mlx_xpm_file_to_image(param->mlx_ptr, "textures/floor_v2.xpm", &param->img_widht, &param->img_height);
	param->collectible = mlx_xpm_file_to_image(param->mlx_ptr, "textures/coin.xpm", &param->img_widht, &param->img_height);
	param->player = mlx_xpm_file_to_image(param->mlx_ptr, "textures/kinght_v2.xpm", &param->img_widht, &param->img_height);
	param->exit = mlx_xpm_file_to_image(param->mlx_ptr, "textures/portal_f0.xpm", &param->img_widht, &param->img_height);
	param->exit_m = mlx_xpm_file_to_image(param->mlx_ptr, "textures/portal_f1.xpm", &param->img_widht, &param->img_height);
}