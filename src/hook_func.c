/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:04:48 by hroxo             #+#    #+#             */
/*   Updated: 2025/11/03 11:12:43 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	handle_key_input(int keysym, t_fractol *fractol)
{
	if (keysym == ESC)
		drop_pane(1, fractol);
	else if (keysym == Q)
		data_init(fractol);
	else if (keysym == A_UP)
		fractol->bound.y_shift -= 0.1;
	else if (keysym == A_DW)
		fractol->bound.y_shift += 0.1;
	else if (keysym == A_RH)
		fractol->bound.x_shift += 0.1;
	else if (keysym == A_LF)
		fractol->bound.x_shift -= 0.1;
	render_fractol(fractol);
	return (0);
}

double	update_axis(int axis_mouse, t_fractol *fractol)
{
	return (map_values(axis_mouse, fractol, WIDTH));
}

int	handle_mouse_input(
		int button, int xaxis_mouse, int yaxis_mouse, t_fractol *fractol)
{
	if (SCROLL_UP == button)
	{
		fractol->bound.x_shift += update_axis(xaxis_mouse, fractol);
		fractol->bound.y_shift += update_axis(yaxis_mouse, fractol);
		fractol->bound.min /= 2;
		fractol->bound.max /= 2;
		fractol->bound.iter += 25;
	}
	else if (SCROLL_DW == button)
	{
		fractol->bound.x_shift -= update_axis(xaxis_mouse, fractol);
		fractol->bound.y_shift -= update_axis(yaxis_mouse, fractol);
		fractol->bound.min *= 2;
		fractol->bound.max *= 2;
		fractol->bound.iter -= 25;
	}
	else if (MOUSE_RH == button)
		fractol->bound.iter += 50;
	else if (MOUSE_LF == button)
		fractol->bound.iter -= 50;
	render_fractol(fractol);
	return (0);
}
