/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:45:58 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/16 11:49:10 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>

# define WINDOW_SIZE	800

#define BLACK 0x330066
#define WHITE 0xFF00FF

# define PSYCHEDELIC_PURPLE 0x800080
# define PSYCHEDELIC_PINK 0xFF1493
# define PSYCHEDELIC_GREEN 0x00FF00
# define PSYCHEDELIC_BLUE 0x0000FF
# define PSYCHEDELIC_ORANGE 0xFFA500
# define PSYCHEDELIC_YELLOW 0xFFFF00
# define PSYCHEDELIC_CYAN 0x00FFFF
# define PSYCHEDELIC_RED 0xFF0000

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pix;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractol
{
	void	*connection;
	void	*window;
	char	*name;
	t_img	img;

	double	escape_value;
	int		iteration_definition;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;
void	putstr(char *s, int fd);
int		ft_strncmp(char *s1, char *s2, int n);
void	fractol_init(t_fractol *fractol);
void	data_init(t_fractol *fracol);
void	fractol_render(t_fractol *fractol);
double	map(double unscaled_num, double new_min, double new_max,
			double old_max);
int		key_shortcuts(int keycode, t_fractol *fractol);
int		mouse_action(t_fractol *fractol);
int		mouse_zoom(int button, int x, int y, t_fractol *fractol);
double	atodbl(char *s);

void	print_options(void);
void	listen_to_hook(t_fractol *fractol);

t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
#endif
