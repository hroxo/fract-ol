/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:20 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/29 21:11:36 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((2 == argc && ft_strncmp(argv[1], "mandelbrot", 10))
		|| 4 == argc && ft_strncmp(argv[1], "julia", 5))
	{
		//This is a TLDR
		init_fractol(&fractol); //TODO fractal
		render_fractol(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
	{
		ft_printf("%s\n", ER_M);
		exit(1);
	}
	return (0);
}
