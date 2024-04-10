/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:17:35 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/10 17:06:05 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_x(t_data *data)
{
	free_then_exit(data);
	return (0);
}

int	handle_key_event(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		free_then_exit(data);
	}
	if (key == ARROW_UP || key == KEY_W)
		data->offset_y -= 50 / data->zoom;
	if (key == ARROW_LEFT || key == KEY_A)
		data->offset_x -= 50 / data->zoom;
	if (key == ARROW_RIGHT || key == KEY_D)
		data->offset_x += 50 / data->zoom;
	if (key == ARROW_DOWN || key == KEY_S)
		data->offset_y += 50 / data->zoom;
	draw_fractal(data);
	return (0);
}

int	handle_mouse_event(int mouse_sym, int x, int y, t_data *data)
{
	if (mouse_sym == SCROLL_UP)
	{
		data->offset_x = (x / data->zoom + data->offset_x) - (x
				/ (data->zoom * 1.50));
		data->offset_y = (y / data->zoom + data->offset_y) - (y
				/ (data->zoom * 1.50));
		data->zoom *= 1.50;
	}
	else if (mouse_sym == SCROLL_DOWN)
	{
		data->offset_x = (x / data->zoom + data->offset_x) - (x
				/ (data->zoom / 1.50));
		data->offset_y = (y / data->zoom + data->offset_y) - (y
				/ (data->zoom / 1.50));
		data->zoom /= 1.50;
	}
	draw_fractal(data);
	return (0);
}
