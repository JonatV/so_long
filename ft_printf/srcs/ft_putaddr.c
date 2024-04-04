/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:39:59 by jveirman          #+#    #+#             */
/*   Updated: 2024/01/21 17:56:00 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printer(unsigned long long addr)
{
	int		count;
	char	*symbols;
	char	temp;

	count = 0;
	symbols = "0123456789abcdef";
	if (addr >= 16)
	{
		temp = ft_printer(addr / 16);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = write(1, &symbols[addr % 16], 1);
	if (temp == -1)
		return (-1);
	return (count + temp);
}

int	ft_putaddr(void *addr)
{
	int	count;
	int	temp;

	if (!addr)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	temp = ft_printer((unsigned long long)addr);
	if (temp == -1)
		return (-1);
	return (count + temp);
}
