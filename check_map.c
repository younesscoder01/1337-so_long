/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:05:46 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/19 18:15:15 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int check_file(char *file_name)
{
    int len;
    int c;

    len = ft_strlen(file_name) - 1;
    c = 0;

    if ('r' == file_name[len--])
        c++;
    if ('e' == file_name[len--])
        c++;
    if ('b' == file_name[len--])
        c++;
    if ('.' == file_name[len--])
        c++;
    if (c == 4)
        return (1);
    return (0);
}


int cheack_wall(char **map, int map_height, int map_widht)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map_height)
    {
        if (map[i][0] != '1')
            break;
        if (map[i][map_widht-1] != '1')
            break;
        i++;
    }
    while (j < map_widht)
    {
        if (map[0][j] != '1')
            break;
        if (map[map_height-1][j] != '1')
            break;
        j++;
    }
    if (i == map_height && j == map_widht)
        return 1;
    return 0;
}
