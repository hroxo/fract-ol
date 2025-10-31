/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:11:43 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/31 09:47:38 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_win, handle_key_input, fractol);
	mlx_hook(fractol->mlx_win, 17, 0, clicked_cross, fractol);
	mlx_mouse_hook(fractol->mlx_win, handle_mouse_input, fractol);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (NULL == fractol->mlx_ptr)
		malloc_error(0, fractol);
	fractol->mlx_win = mlx_new_window(fractol->mlx_ptr, WIDTH,
			HEIGHT, fractol->name);
	if (NULL == fractol->mlx_win)
		malloc_error(1, fractol);
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (NULL == fractol->img.img_ptr)
		malloc_error(2, fractol);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
	hooks(fractol);
	render_fractol(fractol);
}
