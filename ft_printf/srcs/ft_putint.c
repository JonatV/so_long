/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:26:04 by jveirman          #+#    #+#             */
/*   Updated: 2024/01/21 18:17:23 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_int_neg(int num, int *count)
{
	int	temp;

	if (ft_putchar('-') == -1)
		return (-1);
	num = -num;
	temp = ft_putint(num);
	if (temp == -1)
		return (-1);
	*count += temp + 1;
	return (*count);
}

int	ft_putint(int num)
{
	int	count;
	int	temp;

	count = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
		return (ft_int_neg(num, &count));
	if (num > 9)
	{
		temp = ft_putint(num / 10);
		if (temp == -1)
			return (-1);
		count += temp;
		if (ft_putchar((num % 10) + '0') == -1)
			return (-1);
		count++;
	}
	else
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}
