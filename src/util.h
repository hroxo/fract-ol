/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:21:53 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/29 21:34:05 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "/home/hroxo/lib/libft.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ER_M "Please enter\n./fractol mandelbrot or \n./fractol julia <z> <c>"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_img;

typedef struct s_Zvalue
{
	double	real;
	double	i;
}	t_Zvalue;

// typedef enum s_hooks
// {
// 	int	mouse_wheel_up;
// }	t_hooks;
typedef struct s_fractol
{
	char		*name;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	t_Zvalue	z;
	//Hooks
}	t_fractol;

void	init_fractol(t_fractol *fractol);

#endif
