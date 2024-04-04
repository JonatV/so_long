/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:40:07 by jveirman          #+#    #+#             */
/*   Updated: 2024/01/21 18:17:35 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putuint(unsigned int num)
{
	int	count;
	int	temp;

	count = 0;
	if (num > 9)
	{
		temp = ft_putuint(num / 10);
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
