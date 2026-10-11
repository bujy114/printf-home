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

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_char(char c, int *count);
void	ft_string(char *args, int *count);
void	ft_int(int i, int *count);
void	ft_ptr(void *ptr, int *count);
void	ft_unsigned(unsigned int u, int *count);
void	ft_hex(unsigned long n, char c, int *count);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
