/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:20:50 by ysahraou          #+#    #+#             */
/*   Updated: 2024/05/16 16:58:58 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../src_gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
typedef struct	s_param {
	void	*wall;
	void	*player;
	void	*collectible;
	void	*floor;
	void	*exit;
	void	*mlx_ptr;
	void	*mlx_win;
}				t_param;




#endif