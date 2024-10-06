/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:35:40 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/17 14:35:44 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_puthex_fd(unsigned int n, char c)
{
	char	number;
	ssize_t	tmp;
	ssize_t	total;

	total = 0;
	tmp = n % 16;
	number = ((tmp < 10) * (tmp + 48) + (tmp >= 10) * (tmp + 55));
	if (n / 16 > 0)
	{
		tmp = ft_puthex_fd(n / 16, c);
		if (tmp < 0)
			return (-1);
		total += tmp;
	}
	if (c != 'X')
	{
		if (ft_putchar_fd(ft_tolower(number)) < 0)
			return (-1);
	}
	else if (ft_putchar_fd(number) < 0)
		return (-1);
	total++;
	return (total);
}
