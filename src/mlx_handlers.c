/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:17:35 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/05 15:34:02 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_X(t_data *data)
{
	free_then_exit(data);
	return (0);
}

int	handle_key_event(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		free_then_exit(data);
	}
	return (0);
}
