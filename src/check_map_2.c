/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:15:09 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/21 16:58:44 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void check_flood_fill(t_param	*param, char *path)
{
    char	**map_flood;
    map_flood = malloc(sizeof(char *) * (param->map_height + 1));
    get_map(path, map_flood);
	get_p_xy(map_flood, param);
	flood_fill(map_flood, param->p_x, param->p_y, param->map_height, param->map_widht);
	if (check_f(map_flood))
    {
        ft_free(map_flood);
		ft_free(param->map);
        free(param);
        write(2, "Error\n", 6);
        exit(1);
    }
    ft_free(map_flood);
}