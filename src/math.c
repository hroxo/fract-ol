/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:38:25 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/30 22:41:53 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	encode_color(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

double	pixel_to_cord(double value, t_fractol *fractol, double old_max)
{
	return ((fractol->bound.max - fractol->bound.min) * value / old_max + fractol->bound.min);
}

void	calc_z(t_complex *z, t_complex *c)
{
	double	temp_z;

	temp_z = z->real;
	z->real = (z->real * z->real) - (z->i * z->i);
	z->i *= 2 * temp_z;
	z->real += c->real;
	z->i += c->i;
}
