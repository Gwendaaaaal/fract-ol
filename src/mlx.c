/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:30:29 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/09 19:27:03 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <float.h>

void	draw_mandelbrot(t_data *data)
{
	int		i;
	double	temp;

	i = -1;
	data->zx = 0.0;
	data->zy = 0.0;
	data->cx = (data->x / ((float) HEIGHT/2)) - 3.0;
	data->cy = (data->y / ((float) HEIGHT/2)) - 1.0;
	while (++i < MAX_ITER && data->zx * data->zx + data->zy * data->zy <= 4)
	{
		temp = data->zx;
		data->zx = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = 2. * temp * data->zy + data->cy;
	}
	// printf("i = %i\n", i);
	if (i == MAX_ITER)
		img_pix_put(&data->img, data->x, data->y, 0xFF0000);
	else
		img_pix_put(&data->img, data->x, data->y, 0x000000);
}

int	render(t_data *data)
{
    /* if window has been destroyed, we don't want to put the pixel ! */
    if (data->win != NULL)
        mlx_pixel_put(data->mlx, data->win, 
            WIDTH / 2, HEIGHT / 2, 0xFF0000);
    return (0);
}

int draw_fractal(t_data *data)
{
	data->x = 0;
	data->y = 0;
	while (data->y < HEIGHT)
	{
		while(data->x < WIDTH)
		{
			draw_mandelbrot(data);
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
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
	mlx_hook(data->win, DestroyNotify, 0, &handle_X, data);
	mlx_key_hook(data->win, &handle_key_event, data);
	draw_fractal(data);
	mlx_loop(data->mlx);
	return (1);	
}
