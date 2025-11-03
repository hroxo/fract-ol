/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:52:00 by hroxo             #+#    #+#             */
/*   Updated: 2025/11/03 15:12:42 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*offset;

	offset = fractol->img.addr + (y * fractol->img.line_length)
		+ x * (fractol->img.bits_per_pixel / 8);
	*(unsigned int *)offset = color;
}

void	ft_mandelbrot(t_complex *c, t_fractol *fractol, int x, int y)
{
	t_complex	z;
	int			i;

	c->real = map_values((double)x, fractol, WIDTH) + fractol->bound.x_shift;
	c->i = map_values((double)y, fractol, HEIGHT) + fractol->bound.y_shift;
	i = 0;
	z.i = 0;
	z.real = 0;
	while (i < fractol->bound.iter)
	{
		calc_z(&z, c);
		if ((z.real * z.real) + (z.i * z.i)
			> (fractol->bound.esc * fractol->bound.esc))
		{
			my_mlx_pixel_put(fractol, x, y,
				encode_color(i * i, i, i * i / fractol->bound.iter));
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(fractol, x, y, encode_color(0xff / 8, 0, 0xff / 8));
}

void	ft_julia(t_complex *c, t_fractol *fractol, int x, int y)
{
	t_complex	z;
	int			i;

	z.real = map_values((double)x, fractol, WIDTH) + fractol->bound.x_shift;
	z.i = map_values((double)y, fractol, HEIGHT) + fractol->bound.y_shift;
	i = 0;
	c->i = fractol->julia_y;
	c->real = fractol->julia_x;
	while (i < fractol->bound.iter)
	{
		calc_z(&z, c);
		z.i = -1;
		if ((z.real * z.real) + (z.i * z.i)
			< (fractol->bound.esc * fractol->bound.esc))
		{
			my_mlx_pixel_put(fractol, x, y,
				encode_color(i * i, i, i * i / fractol->bound.iter));
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(fractol, x, y, encode_color(0xff / 8, 0, 0xff / 8));
}

void	ft_tricorn(t_complex *c, t_fractol *fractol, int x, int y)
{
	t_complex	z;
	int			i;

	c->real = map_values((double)x, fractol, WIDTH) + fractol->bound.x_shift;
	c->i = map_values((double)y, fractol, HEIGHT) + fractol->bound.y_shift;
	i = 0;
	z.i = 0;
	z.real = 0;
	while (i < fractol->bound.iter)
	{
		calc_z(&z, c);
		z.i *= -1;
		if ((z.real * z.real) + (z.i * z.i)
			> (fractol->bound.esc * fractol->bound.esc))
		{
			my_mlx_pixel_put(fractol, x, y,
				encode_color(i * i, i, i * i / fractol->bound.iter));
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(fractol, x, y, encode_color(0xff / 8, 0, 0xff / 8));
}

void	render_fractol(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(fractol->name, "mandelbrot", 10))
				ft_mandelbrot(&c, fractol, x, y);
			else if (!ft_strncmp(fractol->name, "tricorn", 7))
				ft_tricorn(&c, fractol, x, y);
			else
				ft_julia(&c, fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_win,
		fractol->img.img_ptr, 0, 0);
}
