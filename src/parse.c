/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:23:44 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/11 16:20:50 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_float(char *string)
{
	int	i;

	i = 0;
	if (ft_strchr(string, '.') != ft_strrchr(string, '.'))
		return (0);
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i]) && string[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	get_julia_args(char **argv, t_data *data)
{
	if (is_float(argv[2]) && is_float(argv[3]))
	{
		data->cx = ft_atof(argv[2]);
		data->cy = ft_atof(argv[3]);
		return (1);
	}
	ft_printf("Wrong args for julia set\n");
	return (0);
}

int	parse(int argc, char **argv, t_data *data)
{
	if (argc != 2 && argc != 4)
		return (help(), 0);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		data->query = "julia";
		if (argc == 4)
		{
			if (!get_julia_args(argv, data))
				return (0);
		}
		return (1);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
	{
		data->query = "mandelbrot";
		return (1);
	}
	else if (ft_strncmp(argv[1], "burning-ship", 13) == 0 && argc == 2)
	{
		data->query = "burning-ship";
		return (1);
	}
	return (help(), 0);
}
