/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:04:48 by hroxo             #+#    #+#             */
/*   Updated: 2025/11/03 12:13:02 by hroxo            ###   ########.fr       */
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
		fractol->bound.y_shift -= (0.5 * fractol->bound.zoom);
	else if (keysym == A_DW)
		fractol->bound.y_shift += (0.5 * fractol->bound.zoom);
	else if (keysym == A_RH)
		fractol->bound.x_shift += (0.5 * fractol->bound.zoom);
	else if (keysym == A_LF)
		fractol->bound.x_shift -= (0.5 * fractol->bound.zoom);
	render_fractol(fractol);
	return (0);
}

double	update_axis(int axis_mouse, t_fractol *fractol, int side)
{
	return (map_values(axis_mouse, fractol, side));
}

int	handle_mouse_input(
		int button, int xaxis_mouse, int yaxis_mouse, t_fractol *fractol)
{
	if (SCROLL_UP == button)
	{
		fractol->bound.x_shift += update_axis(xaxis_mouse, fractol, WIDTH);
		fractol->bound.y_shift += update_axis(yaxis_mouse, fractol, HEIGHT);
		fractol->bound.zoom /= 2;
		fractol->bound.iter += 25;
	}
	else if (SCROLL_DW == button)
	{
		fractol->bound.x_shift -= update_axis(xaxis_mouse, fractol, WIDTH);
		fractol->bound.y_shift -= update_axis(yaxis_mouse, fractol, HEIGHT);
		fractol->bound.zoom *= 2;
		fractol->bound.iter -= 25;
	}
	else if (MOUSE_RH == button)
		fractol->bound.iter += 50;
	else if (MOUSE_LF == button)
		fractol->bound.iter -= 50;
	render_fractol(fractol);
	return (0);
}
