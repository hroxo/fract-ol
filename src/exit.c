/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:19:23 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/30 10:49:00 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	malloc_error(int flag, t_fractol *fractol)
{
	if (0 == flag)
		perror("Error Iniciatilizing MLX");
	else if (1 == flag) //Error with new_window
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		perror("Error Iniciatilizing Window");
	}
	else if (2 == flag) //Error with new_image
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
