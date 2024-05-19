/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:20:50 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/19 17:06:06 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../src_gnl/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
typedef struct	s_param {
	void	*wall;
	void	*player;
	void	*collectible;
	void	*floor;
	void	*exit;
	void	*exit_m;
	void	*mlx_ptr;
	void	*mlx_win;
	int		p_x;
	int		p_y;
	int		exit_x;
	int		exit_y;
	char	**map;
	int		coin_c;
}				t_param;

int check_file(char *file_name);
int cheack_wall(char **map, int map_height, int map_widht);

#endif
