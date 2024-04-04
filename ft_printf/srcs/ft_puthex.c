/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:33:23 by jveirman          #+#    #+#             */
/*   Updated: 2024/01/22 11:28:32 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putbase(unsigned int num, char type, unsigned int base)
{
	int		count;
	char	*symbols;
	int		temp;

	count = 0;
	symbols = "0123456789abcdef";
	if (type == 'X')
		symbols = "0123456789ABCDEF";
	if (num < base)
	{
		if (ft_putchar(symbols[num]) == -1)
			return (-1);
		count++;
	}
	else
	{
		temp = ft_putbase(num / base, type, base);
		if (temp == -1)
			return (-1);
		count += temp;
		if (ft_putchar(symbols[num % base]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
