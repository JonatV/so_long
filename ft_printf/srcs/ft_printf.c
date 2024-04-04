/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:25:56 by jveirman          #+#    #+#             */
/*   Updated: 2024/01/22 11:50:00 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_type_handler(char type, int *count_total, va_list *args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (type == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (type == 'p')
		count = ft_putaddr(va_arg(*args, void *));
	else if (type == 'd' || type == 'i')
		count = ft_putint(va_arg(*args, int));
	else if (type == 'u')
		count = ft_putuint(va_arg(*args, unsigned int));
	else if (type == 'x' || type == 'X')
		count = ft_putbase(va_arg(*args, unsigned int), type, 16);
	else if (type == '%')
		count = ft_putchar('%');
	if (count == -1)
		return (-1);
	return (*count_total += count);
}

static int	security_guardian(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1] || !ft_strchr("csxXdiup%", str[i + 1]))
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		count_total;
	int		i;

	if (!security_guardian(str))
		return (-1);
	va_start(va, str);
	count_total = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (ft_type_handler(str[++i], &count_total, &va) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar((char)str[i]) == -1)
				return (-1);
			count_total++;
		}
	}
	va_end(va);
	return (count_total);
}
