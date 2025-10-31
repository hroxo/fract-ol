/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:20 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/31 08:49:52 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	init_basics(t_fractol *fractol, int flag)
{
	fractol->bound.max = 2;
	fractol->bound.min = -2;
	fractol->bound.esc = fractol->bound.max;
	if (!flag)
		fractol->name = "fractol";
	else
		fractol->name = "julia";
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
			init_basics(&fractol, 1);
		else
			init_basics(&fractol, 0);
		init_fractol(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
	{
		ft_printf("%s\n", ER_M);
		exit(1);
	}
	return (0);
}
