/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:02:17 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/29 09:27:28 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/hroxo/lib/libft.h"
#include "util.h"

int	main(int argc, char **argv)
{
	//t_mlx	*mlx;
	void	*mlx_ptr;
	// int	width;
	// int	lenght;

	(void) argv;
	if (2 != argc)
	{
		ft_printf("Erro input add parameter");
		return (1);
	}
	// width = 256;
	// lenght = 256;
	mlx_ptr = mlx_init();
	if (NULL == mlx_ptr)
	{
		ft_printf("ERROR Initializing");
		return (2);
	}
	
	return (0);
}
