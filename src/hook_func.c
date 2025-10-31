/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:04:48 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/31 08:50:44 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	handle_key_input(int keysym, t_fractol *fractol)
{
	if (keysym == 65307)
		drop_pane(1, fractol);
	return (0);
}

int	handle_mouse_input(int button, int x, int y, t_fractol *fractol)
{
	(void) x;
	(void) y;
	if (SCROLL_UP == button)
	{
		fractol->bound.esc *= 0.8;
		color_screen(fractol);
		ft_printf("Mouse scroll up!\n");
	}
	else if (SCROLL_DW == button)
	{
		fractol->bound.esc *= 1.5;
		color_screen(fractol);
		ft_printf("Mouse scroll down!\n");
	}
	return (0);
}
