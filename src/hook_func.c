/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:04:48 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/31 11:56:43 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	handle_key_input(int keysym, t_fractol *fractol)
{
	if (keysym == 65307)
		drop_pane(1, fractol);
	return (0);
}

int	handle_mouse_input(int button, int xaxis_mouse, int yaxis_mouse, t_fractol *fractol)
{
	ft_printf("==>MOUSE AXIS POS<==\nx postion: %d\ny postion: %d\n",xaxis_mouse , yaxis_mouse);
	if (SCROLL_UP == button)
	{
		fractol->bound.esc /= 0.05;
		fractol->bound.min *= 0.8;
		fractol->bound.max *= 0.8;
		ft_printf("Mouse scroll up!\n");
	}
	else if (SCROLL_DW == button)
	{
		fractol->bound.esc *= 0.05;
		fractol->bound.min *= 1.5;
		fractol->bound.max *= 1.5;
		ft_printf("Mouse scroll down!\n");
	}
	render_fractol(fractol);
	return (0);
}
