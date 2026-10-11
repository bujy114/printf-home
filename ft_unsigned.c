/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:21:43 by lsallam           #+#    #+#             */
/*   Updated: 2026/10/06 11:32:42 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int u, int *count)
{
	char	c;

	if (u >= 10)
		ft_unsigned(u / 10, count);
	c = (u % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}
