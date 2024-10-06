/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:31:19 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/18 13:31:21 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenhex(unsigned long long number)
{
	int	total;

	total = 1;
	while (number / 16 > 0)
	{
		number /= 16;
		total++;
	}
	return (total);
}

static void	ft_puthex(unsigned long long number)
{
	if (number < 16)
	{
		if (number < 10)
			ft_putnbr_fd(number);
		else
			ft_putchar_fd('a' + number - 10);
	}
	else
	{
		ft_puthex(number / 16);
		ft_puthex(number % 16);
	}
}

ssize_t	ft_putpoint(void *p)
{
	unsigned long long		number;
	int						total;

	number = (unsigned long long)p;
	total = write(1, "0x", 2);
	if (total < 0)
		return (-1);
	if (p == 0)
		total += write(1, "0", 1);
	else
	{
		ft_puthex(number);
		total += ft_lenhex(number);
	}
	return (total);
}
