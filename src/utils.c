/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:34:05 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/19 16:20:49 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	ft_atof(char *string)
{
	float	number;
	int		left_part;
	int		dec_part;
	char	*right_part;

	number = 0;
	left_part = ft_atoi(string);
	number += (float) left_part;
	right_part = ft_strchr(string, '.') + 1;
	if (!(right_part - 1))
		return (number);
	dec_part = ft_atoi(right_part);
	if (number >= 0)
		number += (float) dec_part / (float)(ft_pow(10, ft_strlen(right_part)));
	else
		number -= (float) dec_part / (float)(ft_pow(10, ft_strlen(right_part)));
	if (ft_strchr(string, '-'))
		return (number * -1);
	else
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

void	help(void)
{
	ft_printf("Availables fractals are : burning-ship, julia, mandelbrot");
	ft_printf(" and tricorn\n\n");
	ft_printf("Usage exemples :\n\n");
	ft_printf("./fractol burning-ship\n");
	ft_printf("./fractol julia\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol tricorn\n\n");
	ft_printf("For julia set, you can enter 2 floats :\n\n");
	ft_printf("./fractol julia 0.285 0.013\n\n");
	ft_printf("Availables commands are :\n\n");
	ft_printf("WASD - ARROWS : Move the view\n");
	ft_printf("MOUSE WHEEL : Zoom in or out following the mouse position\n");
	ft_printf("I - O : Change the color palette\n");
	ft_printf("K - L : Increase or decrease the number of iterations\n");
	ft_printf("COMMA - DOT : Increase or decrease the constants of Julia\n");
}
