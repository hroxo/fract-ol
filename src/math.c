/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:38:25 by hroxo             #+#    #+#             */
/*   Updated: 2025/11/03 14:50:33 by hroxo            ###   ########.fr       */
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
	z->i = (2 * z->real * z->i) + c->i;
	z->real = temp_z;
}

long	ft_atoii(char *s, size_t *i, int *sig)
{
	size_t	j;
	long	i_part;

	i_part = 0;
	j = *i;
	if (s[j] == '-' || s[j] == '+')
	{
		if (s[j] == '-')
			*sig = -1;
		j++;
	}
	while (s[j] && (s[j] >= '0' && s[j] <= '9'))
	{
		i_part = (i_part * 10) + (s[j] - '0');
		j++;
	}
	*i = j;
	return (i_part);
}

double	atodl(char *s)
{
	double	pow;
	long	i_part;
	double	d_part;
	size_t	i;
	int		sig;

	sig = 1;
	pow = 1;
	i_part = 0;
	d_part = 0;
	i = 0;
	while (s[i] && (s[i] == 32 || (s[i] <= 13 && s[i] >= 8)))
		i++;
	i_part = ft_atoii(s, &i, &sig);
	if (s[i] == '.')
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		pow /= 10;
		d_part += ((s[i] - '0') * pow);
		i++;
	}
	return ((d_part + i_part) * sig);
}
