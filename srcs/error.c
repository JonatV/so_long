/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:11:15 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/09 23:10:22 by ventouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_error_reading(int error_case, int fd, char *mem, char *buf)
{
	if (1 == error_case)
		ft_putstr_fd("Error: File descriptor\n", 1);
	else if (2 == error_case)
	{
		ft_putstr_fd("Error: Malloc failed\n", 1);
		close (fd);
	}
	else if (3 == error_case)
	{
		ft_putstr_fd("Error: Ft_strjoin failed\n", 1);
		if (mem)
			free(mem);
		if (buf)
			free(buf);
		close (fd);
	}
	exit(EXIT_FAILURE);
}

void ft_error_reading_1(int error_case, char *mem)
{

	if (1 == error_case)
	{
		ft_putstr_fd("Error: Wrong character found.\n", 1);
		free(mem);
	}
	else if (2 == error_case)
	{
		ft_putstr_fd("Error: Rows have different lengths.\n", 1);
		free(mem);
	}
	exit(EXIT_FAILURE);
}

void ft_error_map(int error_case, char *map_gnl, t_er_map *error_map)
{
	if (1 == error_case)
		ft_putstr_fd("Error: The map must be rectangle.\n", 1);
	else if (2 == error_case)
		ft_putstr_fd("Error: Map too small.\n", 1);
	else if (3 == error_case)
		ft_putstr_fd("Error: Require a minimum of one collectible.\n", 1);
	else if (4 == error_case)
		ft_putstr_fd("Error: Multiple or no START found.\n", 1);
	else if (5 == error_case)
		ft_putstr_fd("Error: Multiple or no EXIT found.\n", 1);
	free(map_gnl);
	free(error_map);
	exit(EXIT_FAILURE);
}
