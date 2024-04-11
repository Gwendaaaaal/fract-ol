/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:44:53 by gholloco          #+#    #+#             */
/*   Updated: 2024/02/02 16:31:50 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char c, va_list args, int *len)
{
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int), len));
	else if (c == 'u')
		return (print_u_int(va_arg(args, unsigned int), len));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'x')
		return (print_hexa(va_arg(args, unsigned int), len));
	else if (c == 'X')
		return (print_hexa_c(va_arg(args, unsigned int), len));
	else if (c == 'p')
		return (print_pointer(va_arg(args, size_t), len));
	else if (c == 'c')
		return (print_char(va_arg(args, int)));
	else
		return (print_percent());
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += format(str[i++ + 1], args, &len);
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		if (str[i])
			i++;
	}
	va_end(args);
	return (len);
}
