/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:39:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/10 16:16:26 by ventouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_char_valid(int c)
{
	if (c == '0' || c == '1' || c == 'E'
		|| c == 'P' || c == 'C' || c == '\n')
	{
		return (1);
	}
	return (0);
}

void	free_matrix(int rows, char **matrix)
{
	int i;

	i = 0;
	while (i < rows && matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}