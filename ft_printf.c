/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 11:28:24 by lsallam           #+#    #+#             */
/*   Updated: 2026/10/06 11:25:36 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type(char sign, va_list *args, int *count)
{
	if (sign == 'c')
		ft_char(va_arg(*args, int), count);
	else if (sign == 's')
		ft_string(va_arg(*args, char *), count);
	else if (sign == 'd' || sign == 'i')
		ft_int(va_arg(*args, int), count);
	else if (sign == 'p')
		ft_ptr(va_arg(*args, void *), count);
	else if (sign == 'u')
		ft_unsigned(va_arg(*args, unsigned int), count);
	else if (sign == 'x' || sign == 'X')
		ft_hex(va_arg(*args, unsigned int), sign, count);
	else if (sign == '%')
		ft_char('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			type(*format, &args, &count);
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
