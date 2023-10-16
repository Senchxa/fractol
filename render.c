/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:46:07 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/15 16:45:27 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pix / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "julia", 5) == 0)
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, 2, WINDOW_SIZE) * fractol->zoom);
	z.y = (map(y, 2, -2, WINDOW_SIZE) * fractol->zoom);
	mandel_or_julia(&z, &c, fractol);
	while (i < fractol->iteration_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, fractol->iteration_definition);
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
