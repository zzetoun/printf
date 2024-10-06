/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:40:41 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/19 10:40:44 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr_fd(long n)
{
	ssize_t		number;
	ssize_t		total;
	ssize_t		tmp;

	total = 0;
	if (n < 0)
	{
		if (ft_putchar_fd('-') < 0)
			return (-1);
		n *= -1;
		total++;
	}
	number = n % 10 + '0';
	if (n / 10 > 0)
	{
		tmp = ft_putnbr_fd(n / 10);
		if (tmp < 0)
			return (-1);
		total += tmp;
	}
	if (ft_putchar_fd(number) < 0)
		return (-1);
	total++;
	return (total);
}
