/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:11:43 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/29 21:33:50 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static int	handle_key_input(int keysym, t_fractol *fractol)
{
	if (keysym == 65307)
	{
		ft_printf("Key ESC was pressed with the keycode: %d\n", keysym);
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		exit(1);
	}
	return (0);
}

void	hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, handle_key_input, fractol);
	mlx_mouse_hook(fractol->mlx_win, handle_mouse_input, fractol);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (NULL == fractol->mlx_ptr)
	{
		perror("Error Iniciatilizing MLX");
		ft_printf("\n");
		exit(1);
	}
	fractol->mlx_win = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, fractol->name);
	if (NULL == fractol->mlx_win)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		perror("Error Iniciatilizing Window");
		ft_printf("\n");
		exit(1);
	
	}
	hooks(fractol);
}
