/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:33:14 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/16 12:44:01 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pix / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	mandel_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
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
