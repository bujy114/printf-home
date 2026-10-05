/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:00:18 by lsallam           #+#    #+#             */
/*   Updated: 2026/10/05 17:20:29 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *args, int *count)
{
	size_t	nofc;

	nofc = ft_strlen(args);
	(*count)+=nofc;
	while(nofc != 0)
	{
		write(1,args, 1);
		args++;
		nofc--;
	}
}
