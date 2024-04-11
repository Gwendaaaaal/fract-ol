/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:34:05 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/11 13:43:46 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

float	ft_atof(char *string)
{
	float	number;
	int		left_part;
	int		right_part;
	char	**parts;

	number = 0;
	parts = ft_split(string, '.');
	left_part = ft_atoi(parts[0]);
	right_part = ft_atoi(parts[1]);
	number += (float) left_part;
	if (number >= 0)
		number += (float) right_part / (float)(ft_pow(10, ft_strlen(parts[1])));
	else
		number -= (float) right_part / (float)(ft_pow(10, ft_strlen(parts[1])));
	return (number);
}

double	ft_pow(double n1, double n2)
{
	double	dbl;

	dbl = (double) n1;
	while (n2 > 1)
	{
		dbl *= n1;
		n2--;
	}
	return (dbl);
}

double	ft_abs(double n1)
{
	if (n1 < 0)
	{
		return (n1 * -1);
	}
	return (n1);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
