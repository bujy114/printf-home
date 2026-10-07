/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 18:29:46 by lsallam           #+#    #+#             */
/*   Updated: 2026/10/07 18:29:57 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_hex(unsigned long n , char c, int *count)
{
    char *hex;
    if (c == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    if (n < 16)
            ft_char(hex[n], count);
    else
    {
        ft_hex(n/16, c, count);
        ft_char(hex[n%16], count);
    }
}
