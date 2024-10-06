/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:16:50 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/15 12:16:52 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>

int		ft_tolower(int c);
int		ft_printf(const char *prnt, ...);

ssize_t	ft_putchar_fd(char c);
ssize_t	ft_putstr_fd(char *s);
ssize_t	ft_putpoint(void *p);
ssize_t	ft_putunbr_fd(unsigned int n);
ssize_t	ft_puthex_fd(unsigned int n, char c);
ssize_t	ft_putnbr_fd(long n);

size_t	ft_strlen(const char *s);

#endif