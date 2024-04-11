/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:27:13 by gholloco          #+#    #+#             */
/*   Updated: 2024/01/08 12:26:40 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u_int(unsigned int number, int *len)
{
	char	output;

	if (number / 10 > 0)
		print_u_int(number / 10, len);
	output = (number % 10) + 48;
	write(1, &output, 1);
	*len += 1;
	return (0);
}

int	print_int(int n, int *len)
{
	char			output;
	long long int	bigint;

	bigint = (long long int) n;
	if (bigint < 0)
	{
		write(1, "-", 1);
		bigint = -bigint;
		*len += 1;
	}
	if (bigint / 10 > 0)
		print_int(bigint / 10, len);
	output = (bigint % 10) + 48;
	write(1, &output, 1);
	*len += 1;
	return (0);
}
