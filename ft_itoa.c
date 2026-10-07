/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:06:47 by lsallam           #+#    #+#             */
/*   Updated: 2026/09/20 16:08:43 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counter(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ifzero(void)
{
	char	*ptr;

	ptr = malloc(2);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

static char	*fill(int n, int count, char *ptr)
{
	ptr[count] = '\0';
	count--;
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
		while (count >= 1)
		{
			ptr[count] = (n % 10) + '0';
			n = n / 10;
			count--;
		}
	}
	else
	{
		while (count >= 0)
		{
			ptr[count] = (n % 10) + '0';
			n = n / 10;
			count--;
		}
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = malloc(12);
		if (ptr == NULL)
			return (NULL);
		ft_memcpy(ptr, "-2147483648", 12);
		return (ptr);
	}
	if (n == 0)
		return (ifzero());
	count = counter(n);
	ptr = malloc(count + 1);
	if (ptr == NULL)
		return (NULL);
	return (fill(n, count, ptr));
}
