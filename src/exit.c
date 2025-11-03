/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:19:23 by hroxo             #+#    #+#             */
/*   Updated: 2025/11/03 12:27:53 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

void	malloc_error(int flag, t_fractol *fractol)
{
	if (0 == flag)
		perror("Error Iniciatilizing MLX");
	else if (1 == flag)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		perror("Error Iniciatilizing Window");
	}
	else if (2 == flag)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		perror("Error Iniciatilizing Image");
	}
	exit(1);
}

void	drop_pane(int flag, t_fractol *fractol)
{
	if (1 == flag)
		ft_printf("Key ESC was pressef terminating the program\n");
	else if (2 == flag)
		ft_printf("User clicked in Cross, terminating the program\n");
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx_ptr);
	fractol->img.img_ptr = NULL;
	fractol->img.addr = NULL;
	free(fractol->mlx_ptr);
	exit(1);
}

int	clicked_cross(t_fractol *fractol)
{
	drop_pane(2, fractol);
	return (0);
}

void	display_help(void)
{
	char		*help;

	help = "\n==> Welcome to Fract-ol <==\n\n"
		"To run the program please run:\n\n"
		"\t./fractol mandelbrot\n"
		"\t./fractol julia <value1> <value2>\n\n"
		"\tTo zoom in just scroll up\n"
		"\tTo zoom out scroll down\n"
		"\tTo retrieve to initial position just press Q\n"
		"\tTo leave either press Esc or the Cross on top\n\n"
		"ENJOY :D\n";
	ft_printf("%s", help);
	exit(1);
}
