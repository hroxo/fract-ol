/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:02:17 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/29 11:50:18 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/hroxo/lib/libft.h"
#include "util.h"

int	encode_color(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

void	color_screen(t_mlx_data *data, int color)
{
	int	y;
	int	x;
	
	y = HEIGHT/4;
	while (y < 3 * HEIGHT/4)
	{
		x = WIDTH/4;
		while (x < 3 * WIDTH/4)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, color);
			x++;
		}
		y++;
	}
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == 114)
		color_screen(data, encode_color(255, 0, 0));
	else if (keysym == 103)
		color_screen(data, encode_color(0, 255, 0));
	else if (keysym == 98)
		color_screen(data, encode_color(0, 0, 255));
	else if (keysym == 65307)
	{
		ft_printf("Key ESC was pressed with the keycode: %d\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	else
		color_screen(data, encode_color(0, 0, 0));
	return (0);
}

int	main(int argc, char **argv)
{
	// t_mlx	*mlx;
	t_mlx_data	data;

	if (2 != argc || ft_strncmp(argv[1], "run", ft_strlen(argv[1])))
	{
		ft_printf("Erro input add parameter");
		return (1);
	}
	data.mlx_ptr = mlx_init();
	if (NULL == data.mlx_ptr)
	{
		ft_printf("ERROR Initializing");
		return (2);
	}
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (NULL == data.mlx_win)
	{
		mlx_destroy_display(data.mlx_ptr);
		ft_printf("Error opening the Window");
		return (3);
	}
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
