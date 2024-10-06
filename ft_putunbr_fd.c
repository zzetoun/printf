/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:40:27 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/09 15:40:28 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putunbr_fd(unsigned int n)
{
	char	number;
	ssize_t	temp;
	ssize_t	total;

	total = 0;
	number = n % 10 + '0';
	if (n / 10 > 0)
	{
		temp = ft_putnbr_fd(n / 10);
		if (temp < 0)
			return (-1);
		total += temp;
	}
	if (ft_putchar_fd(number) < 0)
		return (-1);
	total++;
	return (total);
}
