/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:28:59 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/31 15:28:59 by hroxo            ###   ########.fr       */
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
# define ER_M "Wrong input use --help to view options\n"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_img;

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef enum s_hooks
{
	SCROLL_UP = 4,
	SCROLL_DW = 5
}	t_hooks;

typedef struct s_bound
{
	double	max;
	double	min;
	double	esc;
	double	x_shift;
	double	y_shift;
	int		iter;
}	t_bound;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	//HooksA
	t_bound		bound;
}	t_fractol;

void	init_fractol(t_fractol *fractol);
void	drop_pane(int flag, t_fractol *fractol);
void	malloc_error(int flag, t_fractol *fractol);
int		clicked_cross(t_fractol *fractol);
int		handle_mouse_input(int button, int x, int y, t_fractol *fractol);
int		handle_key_input(int keysym, t_fractol *fractol);
void	render_fractol(t_fractol *fractol);
int		is_fractol(t_complex c, int *i);
int		encode_color(unsigned char r, unsigned char g, unsigned char b);
void	calc_z(t_complex *z, t_complex *c);
double	map_values(double value, t_fractol *fractol, double old_max);
void	data_init(t_fractol *fractol);
void	ft_mandelbrot(t_complex *c, t_fractol *fractol, int x, int y);
void	display_help(void);

#endif
