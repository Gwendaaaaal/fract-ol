/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/04 18:00:05 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <X11/keysym.h>

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_key_event(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.win = mlx_new_window(data.mlx, 1200, 900, "oui");
	if (!data.win)
		return (free(data.win), 0);
	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_key_hook(data.win, &handle_key_event, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
