/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:11:15 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/12 13:23:29 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_maps(int error_case, int fd, char *mem, char *buf)
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

void	ft_error_maps_1(int error_case, char *mem)
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
