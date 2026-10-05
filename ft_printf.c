/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 11:28:24 by lsallam           #+#    #+#             */
/*   Updated: 2026/10/05 17:20:00 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type(char sign, va_list args, int *count)
{
	if (sign == 'c')
		ft_char(va_arg(args, int), count);
	if (sign == 's')
		ft_string(va_arg(args, char *), count);
	if (sign == 'd' || sign == 'i')
		ft_int(va_arg(args, int), count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list args;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			type(*format, args, &count);
			format++;
			continue ;
		}
		write(1, format, 1);
		format++;
		count++;
	}
	va_end(args);
	return (count);
}
