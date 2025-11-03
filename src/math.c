/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:38:25 by hroxo             #+#    #+#             */
/*   Updated: 2025/11/03 12:59:57 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	encode_color(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

double	map_values(double value, t_fractol *fractol, double old_max)
{
	return ((fractol->bound.max - fractol->bound.min)
		* value / old_max + fractol->bound.min);
}

void	calc_z(t_complex *z, t_complex *c)
{
	double	temp_z;

	temp_z = (z->real * z->real) - (z->i * z->i) + c->real;
	z->i = 2 * z->real * z->i + c->i;
	z->real = temp_z;
}

double	atodl(char *s)
{
	double	pow;
	long	i_part;
	double	d_part;
	size_t	i;
	int	sig;

	sig = 1;
	pow = 1;
	i_part = 0;
	d_part = 0;
	i = 0;
	while (s[i] && (s[i] == 32 || (s[i] <= 13 && s[i] >= 8)))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		i++;
	}
	while (s[i] && s[i] != '.' && (s[i] >= '0' && s[i] <= '9'))
	{
		i_part = (i_part * 10) + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		pow /= 10;
		d_part += ((s[i] - '0')* pow);
		i++;
	}
	return ((d_part + i_part) * sig);
}
