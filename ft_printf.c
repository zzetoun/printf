/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:26:17 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/15 12:26:19 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_print(int idx, const char *prnt, va_list args);

int	ft_printf(const char *prnt, ...)
{
	va_list		args;
	int			idx;
	ssize_t		total;
	int			tmp;

	if (!prnt)
		return (0);
	va_start(args, prnt);
	idx = -1;
	total = 0;
	while (prnt[++idx])
	{
		if (prnt[idx] == '%' && prnt[idx++ + 1] != '\0')
			tmp = ft_print(idx, prnt, args);
		else
			tmp = ft_putchar_fd(prnt[idx]);
		if (tmp < 0)
			return (-1);
		total += tmp;
	}
	va_end(args);
	return ((int)total);
}

static int	ft_print(int idx, const char *prnt, va_list args)
{
	if (prnt[idx] == 'd')
		return (ft_putnbr_fd(va_arg(args, int)));
	else if (prnt[idx] == 'c')
		return (ft_putchar_fd((char)va_arg(args, int)));
	else if (prnt[idx] == 's')
		return (ft_putstr_fd(va_arg(args, char *)));
	else if (prnt[idx] == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int)));
	else if (prnt[idx] == 'x' || prnt[idx] == 'X')
		return (ft_puthex_fd((int)va_arg(args, int), prnt[idx]));
	else if ((prnt[idx] == 'i'))
		return (ft_putnbr_fd(va_arg(args, int)));
	else if (prnt[idx] == 'p')
		return (ft_putpoint(va_arg(args, void *)));
	else if (prnt[idx] == '%')
		return (ft_putchar_fd('%'));
	return (0);
}
