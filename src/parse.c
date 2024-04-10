/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:23:44 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/10 19:56:03 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	parse(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		data->query = "julia";
		if (argc == 4)
		{
			data->cx = ft_atof(argv[2]);
			data->cy = ft_atof(argv[3]);
			// printf("data->cx = %lf data->cy = %lf \n", data->cx, data->cy);
		}
		return (1);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		data->query = "mandelbrot";
		return (1);
	}
	else if (ft_strncmp(argv[1], "burning-ship", 13) == 0)
	{
		data->query = "burning-ship";
		return (1);
	}
	return (0);
}
