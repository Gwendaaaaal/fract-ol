/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:30:29 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/05 17:52:59 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandelbrot(t_data *data)
{
}

int draw_fractal(t_data *data)
{
	int i = 0;
	while (i++ < 100)
		img_pix_put(data->img.img, i, i, 0x8c00ff);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "oui");
	if (!data->win)
		return (free(data->win), 0);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
		return (0);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&(data->img.bpp), &(data->img.line_len), &(data->img.endian));
	if (!data->img.addr)
		return (0);
	mlx_loop_hook(data->mlx, &draw_fractal, data);
	mlx_hook(data->win, DestroyNotify, 0, &handle_X, data);
	mlx_key_hook(data->win, &handle_key_event, data);
	mlx_loop(data->mlx);
	return (1);	
}
