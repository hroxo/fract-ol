/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:21:53 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/29 11:38:54 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

# define WIDTH 512
# define HEIGHT 512

typedef struct mlx
{
	void	*window;
	void	*context;
	int		width;
	int		height;
	double	delta_time;
}	t_mlx;

typedef struct mlx_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_mlx_data;
#endif
