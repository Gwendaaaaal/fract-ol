/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <gwendal.hollocou@orange.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:26:30 by gholloco          #+#    #+#             */
/*   Updated: 2024/01/15 14:49:40 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		print_char(char c);
int		print_percent(void);
int		print_string(char *string);
int		print_pointer(size_t number, int *len);
int		print_hexa_size_t(unsigned long long number, int *len);
int		print_hexa(unsigned int number, int *len);
int		print_hexa_c(unsigned int number, int *len);
int		print_u_int(unsigned int number, int *len);
int		print_int(int n, int *len);
int		format(char c, va_list args, int *len);
int		ft_printf(const char *str, ...);

#endif
