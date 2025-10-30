/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:21:53 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/30 12:37:06 by hroxo            ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 800
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

typedef enum s_hooks
{
	SCROLL_UP = 4,
	SCROLL_DW = 5
}	t_hooks;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	//Hooks
}	t_fractol;

void	init_fractol(t_fractol *fractol);
void	drop_pane(int flag, t_fractol *fractol);
void	malloc_error(int flag, t_fractol *fractol);
int		clicked_cross(t_fractol *fractol);
int		handle_mouse_input(int button, int x, int y, t_fractol *fractol);
int		handle_key_input(int keysym, t_fractol *fractol);
//DL ME
void	color_screen(t_fractol *data);
int	is_fractol(t_Zvalue c);

#endif
