/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:31:42 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/25 21:32:53 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	close_win(t_param *param)
{
	mlx_destroy_window(param->mlx_ptr, param->mlx_win);
	free_all_imgs(param);
	exit(0);
}