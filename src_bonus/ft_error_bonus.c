/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:27:32 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/27 13:22:01 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error_map(t_param *param)
{
	write(2, "Error\n", 6);
	ft_free(param->map);
	free(param);
	exit(13);
}
