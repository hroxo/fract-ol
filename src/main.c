/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:51:20 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/31 10:25:56 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"


int	main(int argc, char **argv)
{
	t_fractol	fractol;
	int flag;

	flag = 0;
	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
			flag = 1; 
		init_fractol(&fractol, flag);
		mlx_loop(fractol.mlx_ptr);
	}
	else
	{
		ft_printf("%s\n", ER_M);
		exit(1);
	}
	return (0);
}
