/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:11:15 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/10 17:08:44 by ventouse         ###   ########.fr       */
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

void ft_error_map_1(int *rc, char *map_gnl, t_er_map *error_map, char **matrix)
{
	ft_putstr_fd("Error: Memory allocation failed for the matrix\n", 1);
	if (matrix)
		free_matrix(rc[0], matrix);
	free(map_gnl);
	free(error_map);
	exit(EXIT_FAILURE);	
}

int	ft_error_map_2(int t_b_l_r[4])
{
	int	ret;

	ret = 1;
	if (t_b_l_r[0] > 0 || t_b_l_r[1] > 0 || t_b_l_r[2] > 0 || t_b_l_r[3] > 0)
		ret = 0;
	if (t_b_l_r[0] > 0 && t_b_l_r[1] > 0 && t_b_l_r[2] > 0 && t_b_l_r[3] > 0)
	{
		ft_putstr_fd("Error: Please make and effort, holes everywhere...\n", 1);
		return (ret);
	}
	if (t_b_l_r[0] > 0)
		ft_putstr_fd("Error: Top wall is not that solid.\n", 1);
	if (t_b_l_r[1] > 0)
		ft_putstr_fd("Error: Bottom wall must be made of 1's.\n", 1);
	if (t_b_l_r[2] > 0)
		ft_putstr_fd("Error: Left wall must be made of 1's.\n", 1);
	if (t_b_l_r[3] > 0)
		ft_putstr_fd("Error: Right wall must be made of 1's.\n", 1);
	return (ret);
}
