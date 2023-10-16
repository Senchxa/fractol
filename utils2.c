/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnoll <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:11:24 by dnoll             #+#    #+#             */
/*   Updated: 2023/10/15 15:59:23 by dnoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*double	atodbl(char *s)
{
	long	int_part;
	double	fract_part;
	double	pow;
	int		sign;

	int_part = 0;
	fract_part = 0;
	sign = 1;
	pow = 1;
	while (*s >= 9 && *s <= 13 || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*(s++) - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		fract_part = fract_part + (*(s++) - '0') * pow;
	}
	return ((int_part + fract_part) * sign);
}*/

double	parseinteger(char *s)
{
	long	int_part;
	int		sign;

	int_part = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*(s++) - '0');
	return (int_part * sign);
}

double	parsefraction(char *s)
{
	double	fract_part;
	double	pow;

	fract_part = 0;
	pow = 1;
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		fract_part += (*(s++) - '0') * pow;
	}
	return (fract_part);
}

double	atodbl(char *s)
{
	double	int_part;
	double	fract_part;

	int_part = parseinteger(s);
	fract_part = parsefraction(s);
	return (int_part + fract_part);
}
