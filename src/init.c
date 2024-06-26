/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:49:50 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/19 15:26:39 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!data->win)
		return (free(data->mlx), 0);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
		return (mlx_destroy_window(data->mlx, data->win), free(data->mlx), 0);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&(data->img.bpp), &(data->img.line_len), &(data->img.endian));
	if (!data->img.addr)
		return (free_then_exit(data), 0);
	mlx_hook(data->win, DestroyNotify, 0, &handle_x, data);
	mlx_key_hook(data->win, &handle_key_event, data);
	mlx_mouse_hook(data->win, &handle_mouse_event, data);
	draw_fractal(data);
	mlx_loop(data->mlx);
	return (1);
}

void	init_data(t_data *data)
{
	data->color = 0x0A0A0A;
	data->max_itr = 61;
	data->zoom = (float) HEIGHT / 2.0;
	data->cx = -500.00;
	data->cy = -500.00;
	data->offset_x = -2.5;
	data->offset_y = -1.0;
}
