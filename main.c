/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:37:04 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/15 17:16:56 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fractol.name = argv[1];
		if (ft_strncmp(fractol.name, "julia", 5) == 0)
		{
			fractol.julia_x = atodbl(argv[2]);
			fractol.julia_y = atodbl(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		listen_to_hook(&fractol);
		mlx_loop(fractol.connection);
	}
	else
	{
		print_options();
		exit(1);
	}
}
