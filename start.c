/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:23:58 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/15 16:54:37 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iteration_definition = 25;
	fractol->zoom = 1.0;
}

void	fractol_init(t_fractol *fractol)
{
	fractol->connection = mlx_init();
	fractol->window = mlx_new_window(fractol->connection,
			WINDOW_SIZE,
			WINDOW_SIZE,
			fractol->name);
	if (fractol->window == NULL)
	{
		mlx_destroy_window(fractol->connection, fractol->window);
		free(fractol->connection);
	}
	fractol->img.img_ptr = mlx_new_image(fractol->connection,
			WINDOW_SIZE,
			WINDOW_SIZE);
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pix,
			&fractol->img.line_len,
			&fractol->img.endian);
	data_init(fractol);
}
