/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:52:00 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/30 13:05:54 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*offset;

	offset = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)offset = color;
}

static int encode_color(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

static double	pixel_to_cord(double value, double new_max, double new_min,
		double old_max, double old_min)
{
	return ((new_max - new_min) * (value - old_min) / (old_max - old_min) + new_min);
}

static void	paint(t_fractol *data)
{
	int	x;
	int	y;
	t_Zvalue	c;
	int	i;

	i = 0;
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = pixel_to_cord((double)x, 2, -2, WIDTH, 0);
			c.i = pixel_to_cord((double)y, 2, -2, HEIGHT, 0);
			is_fractol(c, &i);
			my_mlx_pixel_put(data, x, y, encode_color(255/i, 0xff/i, 0xff/i));
			x++;
		}
		y++;
	}
}

void	color_screen(t_fractol *data)
{
	paint(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
}
