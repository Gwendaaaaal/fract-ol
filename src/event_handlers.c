/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:17:35 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/19 13:47:02 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	else if (key == ARROW_UP || key == KEY_W)
		data->offset_y -= 100 / data->zoom;
	else if (key == ARROW_LEFT || key == KEY_A)
		data->offset_x -= 100 / data->zoom;
	else if (key == ARROW_RIGHT || key == KEY_D)
		data->offset_x += 100 / data->zoom;
	else if (key == ARROW_DOWN || key == KEY_S)
		data->offset_y += 100 / data->zoom;
	else if (key == KEY_I && data->color > 0x000033)
		data->color *= 0.62;
	else if (key == KEY_O && data->color < 0xFFFFDD)
		data->color /= 0.62;
	else if (key == KEY_K && data->max_iter < 300)
		data->max_iter += 30;
	else if (key == KEY_L && data->max_iter > 30)
		data->max_iter -= 30;
	else if (key == KEY_COMMA && ft_strncmp(data->query, "julia", 6) == 0)
		data->cx += 0.008;
	else if (key == KEY_DOT && ft_strncmp(data->query, "julia", 6) == 0)
		data->cx -= 0.008;
	return (draw_fractal(data), 0);
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
