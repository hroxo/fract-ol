/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:02:17 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/29 19:33:15 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	encode_color(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*offset;

	offset = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)offset = color;
}
void	paint(t_fractal *data, int color)
{
	int	x;
	int	y;

	y = HEIGHT / 4;
	while (y <= (HEIGHT * 3) / 4)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	color_screen(t_fractal *data, int color)
{
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	paint(data, color);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}

int	handle_input(int keysym, t_fractal *data)
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
	t_fractal	data;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		data.mlx_ptr = mlx_init();
		if (NULL == data.mlx_ptr)
		{
			perror("Error Inicializing MLX");
			exit(2);
		}
		data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
		if (NULL == data.mlx_win)
		{
			mlx_destroy_display(data.mlx_ptr);
			perror("Error Creating Window");
			exit(3);
		}
		mlx_key_hook(data.mlx_win, handle_input, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
	{
		ft_printf("%s", ER_M);
		exit(1);
	}
	return (0);
}
