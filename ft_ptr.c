/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:16:27 by lsallam           #+#    #+#             */
/*   Updated: 2026/10/06 14:16:31 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pri(unsigned long p, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (p >= 16)
		pri(p / 16, count);
	write(1, &hex[p % 16], 1);
	(*count)++;
}

void	ft_ptr(void *ptr, int *count)
{
	unsigned long	p;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);
	(*count) += 2;
	pri(p, count);
}
