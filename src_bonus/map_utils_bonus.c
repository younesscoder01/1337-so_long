/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:48:36 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/25 21:32:39 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	get_map_height(char *path)
{
	int		map_fd;
	int		map_height;
	char	*str;

	map_fd = open(path, O_RDONLY);
	str = get_next_line(map_fd);
	map_height = 0;
	while (str)
	{
		map_height++;
		free(str);
		str = get_next_line(map_fd);
	}
	close(map_fd);
	return (map_height);
}

int	get_map_widht(char *str_map)
{
	int	map_widht;

	map_widht = 0;
	while (str_map[map_widht] != '\n')
		map_widht++;
	return (map_widht);
}

void	get_map(char *path, char **map)
{
	int map_fd;
	char *str;
	int i;

	i = 0;
	map_fd = open(path, O_RDONLY);
	str = get_next_line(map_fd);
	while (str)
	{
		map[i] = str;
		str = get_next_line(map_fd);
		i++;
	}
	map[i] = 0;
	close(map_fd);
}