/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:46:07 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/16 12:52:12 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

static t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale(x, -2, 2, WINDOW_SIZE) * fractol->zoom);
	z.y = (scale(y, 2, -2, WINDOW_SIZE) * fractol->zoom);
	mandel_or_julia(&z, &c, fractol);
	while (i < fractol->iteration_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = scale(i, BLACK, WHITE, fractol->iteration_definition);
			pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	pixel_put(x, y, &fractol->img, PSYCHEDELIC_PINK);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_SIZE)
	{
		x = -1;
		while (++x < WINDOW_SIZE)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->connection,
		fractol->window,
		fractol->img.img_ptr,
		0,
		0);
}
