/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:01:47 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/15 17:19:24 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	listen_to_hook(t_fractol *fractol)
{
	mlx_hook(fractol->window, KeyPress, KeyPressMask, key_shortcuts, fractol);
	mlx_hook(fractol->window, DestroyNotify,
		StructureNotifyMask, mouse_action, fractol);
	mlx_hook(fractol->window, ButtonPress,
		ButtonPressMask, mouse_zoom, fractol);
}
