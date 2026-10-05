/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:57:46 by lsallam           #+#    #+#             */
/*   Updated: 2026/10/05 17:26:27 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../final/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int     ft_printf(const char *format, ...);
void	ft_char(char c, int *count);
void    ft_string(char *args, int *count);
void ft_int(int i, int *count);

#endif
