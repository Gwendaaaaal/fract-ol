/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/11 14:49:08 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (!parse(argc, argv, &data))
		return (0);
	if (!init_mlx(&data))
		return (0);
	return (0);
}
