/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:39:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/08 16:48:45 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_char_valid(int c)
{
	printf("-- here\n"); //debug

	if (c == '0' || c == '1' || c == 'E'
		|| c == 'P' || c == 'C' || c == '\n')
	{
		printf("%c is valid \n", c);
		return (1);
	}
	return (0);
}