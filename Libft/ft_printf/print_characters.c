/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:56:35 by gholloco          #+#    #+#             */
/*   Updated: 2023/12/01 18:17:37 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	print_string(char *string)
{
	int		len;

	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (string[len])
	{
		write(1, &(string[len]), 1);
		len++;
	}
	return (len);
}
