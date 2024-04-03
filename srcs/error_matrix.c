/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:34 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/03 12:19:27 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_matrix(int error_case, char *map_gnl, t_er_map *error_map)
{
	if (1 == error_case)
		ft_putstr_fd("Error: The map must be a rectangle.\n", 1);
	else if (2 == error_case)
		ft_putstr_fd("Error: Map too small.\n", 1);
	else if (3 == error_case)
		ft_putstr_fd("Error: Require a minimum of one collectible.\n", 1);
	else if (4 == error_case)
		ft_putstr_fd("Error: Multiple or no START found.\n", 1);
	else if (5 == error_case)
		ft_putstr_fd("Error: Multiple or no EXIT found.\n", 1);
	if (map_gnl)
		free(map_gnl);
	if (error_map)
		free(error_map);
	exit(EXIT_FAILURE);
}

void	ft_error_matrix_1(int *rc, char *map_gnl, 
		t_er_map *error_map, char **matrix)
{
	ft_putstr_fd("Error: Memory allocation failed for the matrix\n", 1);
	if (matrix)
		free_matrix(rc[0], matrix);
	if (map_gnl)
		free(map_gnl);
	if (error_map)
		free(error_map);
	exit(EXIT_FAILURE);
}

int	ft_error_matrix_2(int t_b_l_r[4])
{
	int	ret;

	ret = 1;
	if (t_b_l_r[0] > 0 || t_b_l_r[1] > 0 || t_b_l_r[2] > 0 || t_b_l_r[3] > 0)
		ret = 0;
	if (t_b_l_r[0] > 0 && t_b_l_r[1] > 0 && t_b_l_r[2] > 0 && t_b_l_r[3] > 0)
	{
		ft_putstr_fd("Error: Please make an effort, holes everywhere...\n", 1);
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
