/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:20:41 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/23 21:07:25 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_param	*param;

	if (argc != 2)
		ft_error_exit();
	if (!check_file(argv[1]))
		ft_error_exit();
	param = malloc(sizeof(t_param));
	param->img_widht = 34;
	param->img_height = 34;
	param->p_moves = 0;
	param->map_height = get_map_height(argv[1]);
	param->map = malloc(sizeof(char *) * (param->map_height + 1));
	get_map(argv[1], param->map);
	param->map_widht = get_map_widht(param->map[0]);
	if (!cheack_wall(param->map, param->map_height, param->map_widht) || check_len(param->map))
		ft_error_wall(param);
	check_flood_fill(param, argv[1]);
	allocation(param);
	put_env(param->mlx_ptr, param->mlx_win, param);
	mlx_string_put(param->mlx_ptr, param->mlx_win, 2, 20, 0XFFFFFF, "Moves : ");
	mlx_string_put(param->mlx_ptr, param->mlx_win, 50, 20, 0XFFFFFF, "0");
	mlx_hook(param->mlx_win, 2, 1L<<0, key_p, param);
	mlx_loop(param->mlx_ptr);
}



