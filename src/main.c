/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:20 by hroxo             #+#    #+#             */
/*   Updated: 2025/11/03 14:56:27 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		init_fractol(&fractol);
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractol.julia_x = atodl(argv[2]);
			fractol.julia_y = atodl(argv[3]);
		}
		render_fractol(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else if (2 == argc && !ft_strncmp(argv[1], "--help", 6))
		display_help();
	else
	{
		ft_printf("%s\n", ER_M);
		exit(1);
	}
	return (0);
}
