/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:27:32 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/23 11:11:51 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void free_all_imgs(t_param *param)
{
    mlx_destroy_image(param->mlx_ptr, param->wall);
    mlx_destroy_image(param->mlx_ptr, param->floor);
    mlx_destroy_image(param->mlx_ptr, param->exit);
    mlx_destroy_image(param->mlx_ptr, param->exit_m);
    mlx_destroy_image(param->mlx_ptr, param->collectible);
    mlx_destroy_image(param->mlx_ptr, param->player);
    mlx_destroy_image(param->mlx_ptr, param->player_left);
    //mlx_destroy_window(param->mlx_ptr, param->mlx_win);
    mlx_destroy_display(param->mlx_ptr);
    free(param->mlx_ptr);
    ft_free(param->map);
    free(param);
}

void ft_error_exit(void)
{
    int ret;
    
    ret = write(2, "Error\n", 6);
    (void)ret;
    exit(1);
}


void ft_error_wall(t_param *param)
{
    int ret;
    
    ret = write(2, "Error\n", 6);
    (void)ret;
    ft_free(param->map);
    free(param);
    exit(1);
}