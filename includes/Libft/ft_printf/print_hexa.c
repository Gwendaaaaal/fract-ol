/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:29:18 by gholloco          #+#    #+#             */
/*   Updated: 2024/01/09 17:52:35 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_size_t(unsigned long long number, int *len)
{
	char	output;
	char	*string;

	string = "0123456789abcdef";
	if (number / 16 > 0)
		print_hexa_size_t(number / 16, len);
	output = string[number % 16];
	write(1, &output, 1);
	*len += 1;
	return (0);
}

int	print_pointer(size_t number, int *len)
{
	if (!number)
	{
		write(1, "(nil)", 5);
		*len += 5;
		return (0);
	}
	write(1, "0x", 2);
	*len += 2;
	print_hexa_size_t(number, len);
	return (0);
}

int	print_hexa(unsigned int number, int *len)
{
	char	output;
	char	*string;

	string = "0123456789abcdef";
	if (number / 16 > 0)
		print_hexa(number / 16, len);
	output = string[number % 16];
	write(1, &output, 1);
	*len += 1;
	return (0);
}

int	print_hexa_c(unsigned int number, int *len)
{
	char	output;
	char	*string;

	string = "0123456789ABCDEF";
	if (number / 16 > 0)
		print_hexa_c(number / 16, len);
	output = string[number % 16];
	write(1, &output, 1);
	*len += 1;
	return (0);
}
