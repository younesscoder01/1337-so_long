/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:20:41 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/21 16:48:14 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	param->img_widht = 34;
	param->img_height = 34;
	param->p_moves = 0;
	if (argc != 2)
		ft_error_exit(param);
	if (!check_file(argv[1]))
		ft_error_exit(param);
	param->map_height = get_map_height(argv[1]);
	param->map = malloc(sizeof(char *) * (param->map_height + 1));
	get_map(argv[1], param->map);
	param->map_widht = get_map_widht(param->map[0]);
	if (!cheack_wall(param->map, param->map_height, param->map_widht))
		ft_error_wall(param);
	check_flood_fill(param, argv[1]);
	allocation(param);
	put_env(param->mlx_ptr, param->mlx_win, param);
	mlx_hook(param->mlx_win, 2, 1L<<0, key_p, param);
	mlx_loop(param->mlx_ptr);
}



