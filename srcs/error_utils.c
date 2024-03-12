/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:39:27 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/12 15:34:07 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_file_valid(char *str)
{
	if (ft_strlen(str) >= 4 && 
		ft_strncmp(".ber", str + ft_strlen(str) - 4, 4) == 0)
		return (1);
	ft_putstr_fd("Error: File extension must be .ber\n", 1);
	exit(EXIT_FAILURE);
}

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
	int	i;

	i = 0;
	while (i < rows && matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
