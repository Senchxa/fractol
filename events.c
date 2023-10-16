/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:22:26 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/15 16:48:42 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_options(void)
{
	putstr("Please enter arguments in this format:\n", 1);
	putstr("1)./fractol mandelbrot\n", 1);
	putstr("2)./fractol julia -0.162 1.04\n", 1);
	putstr("3)./fractol julia -1.476 0\n", 1);
	putstr("4)./fractol julia -0.12 -0.77\n", 1);
}

int	key_shortcuts(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fractol->connection, fractol->img.img_ptr);
		mlx_destroy_window(fractol->connection, fractol->window);
		mlx_destroy_display(fractol->connection);
		free(fractol->connection);
		exit(1);
	}
	return (0);
}

int	mouse_action(t_fractol *fractol)
{
	mlx_destroy_image(fractol->connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->connection, fractol->window);
	mlx_destroy_display(fractol->connection);
	free(fractol->connection);
	exit(1);
}

int	mouse_zoom(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		fractol->zoom *= 0.98;
	}
	else if (button == Button5)
	{
		fractol->zoom *= 1.02;
	}
	fractol_render(fractol);
	return (0);
}
