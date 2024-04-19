/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:30:29 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/17 14:53:12 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <float.h>

void	draw_mandelbrot(t_data *data)
{
	int		i;
	double	temp;

	i = -1;
	data->zx = 0.0;
	data->zy = 0.0;
	data->cx = (data->x / data->zoom) + data->offset_x;
	data->cy = (data->y / data->zoom) + data->offset_y;
	while (++i < data->max_iter && data->zx * data->zx + data->zy * data->zy <= 4)
	{
		temp = data->zx;
		data->zx = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = 2. * temp * data->zy + data->cy;
	}
	if (i == data->max_iter)
		img_pix_put(&data->img, data->x, data->y, 0x000000);
	else
		img_pix_put(&data->img, data->x, data->y, data->color * i);
}

void	draw_julia(t_data *data)
{
	int		i;
	double	temp;

	i = -1;
	data->zx = (data->x / data->zoom) + data->offset_x;
	data->zy = (data->y / data->zoom) + data->offset_y;
	if (data->cx == -500.00 && data->cy == -500.00)
	{
		data->cx = 0.400;
		data->cy = 0.20;
	}
	while (++i < data->max_iter && data->zx * data->zx + data->zy * data->zy <= 4)
	{
		temp = data->zx;
		data->zx = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = 2. * temp * data->zy + data->cy;
	}
	if (i == data->max_iter)
		img_pix_put(&data->img, data->x, data->y, 0x000000);
	else
		img_pix_put(&data->img, data->x, data->y, data->color * i);
}

void	draw_burning_ship(t_data *data)
{
	int		i;
	double	temp;

	i = -1;
	data->zx = 0.0;
	data->zy = 0.0;
	data->cx = (data->x / data->zoom) + data->offset_x;
	data->cy = (data->y / data->zoom) + data->offset_y;
	while (++i < data->max_iter && data->zx * data->zx + data->zy * data->zy <= 4)
	{
		temp = data->zx;
		data->zx = ft_abs(data->zx * data->zx - data->zy * data->zy + data->cx);
		data->zy = ft_abs(2. * temp * data->zy) + data->cy;
	}
	if (i == data->max_iter)
		img_pix_put(&data->img, data->x, data->y, 0x000000);
	else
		img_pix_put(&data->img, data->x, data->y, data->color * i);
}

int	draw_fractal(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->y < HEIGHT)
	{
		while (data->x < WIDTH)
		{
			if (ft_strncmp(data->query, "mandelbrot", 11) == 0)
				draw_mandelbrot(data);
			else if (ft_strncmp(data->query, "julia", 6) == 0)
				draw_julia(data);
			else if (ft_strncmp(data->query, "burning-ship", 13) == 0)
				draw_burning_ship(data);
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
