/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:52:00 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/30 20:08:29 by hroxo            ###   ########.fr       */
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

static void	loop(t_complex *c, t_fractol *fractol, int x, int y)
{
	t_complex	z;
	int			i;

	i = 0;
	z.i = 0;
	z.real = 0;
	i = 1;
	while (i < 50)
	{
		calc_z(&z, c);
		if ((z.real * z.real) + (z.i * z.i) > 4)
		{
			my_mlx_pixel_put(fractol, x, y,
				encode_color(255 / i, 0xff / i, 0xff));
			return ;
		}
		i++;
	}
	return ;
}

static void	paint(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = pixel_to_cord((double)x, 2, -2, WIDTH);
			c.i = pixel_to_cord((double)y, 2, -2, HEIGHT);
			loop(&c, fractol, x, y);
			x++;
		}
		y++;
	}
}

void	color_screen(t_fractol *fractol)
{
	paint(fractol);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_win,
		fractol->img.img_ptr, 0, 0);
}
