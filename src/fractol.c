/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:51:25 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/30 12:41:49 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static t_Zvalue	loop(t_Zvalue c)
{
	int	i;
	double	z_temp;
	t_Zvalue	z;

	z.i = 0;
	z.real = 0;
	i = 0;
	while (i < 50 && (z.real * z.real + z.i * z.i <= 4))
	{
		z_temp = z.real;
		z.real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z_temp * z.i;
		z.real += c.real;
		z.i += c.i;
		i++;
	}
	return (z);
}

int	is_fractol(t_Zvalue c)
{
	t_Zvalue	z;

	z = loop(c);
	if (z.real * z.real + z.i * z.i <= 4)
		return(0);
	return (1);
}
