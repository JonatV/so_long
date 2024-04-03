/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pathfinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:29:40 by ventouse          #+#    #+#             */
/*   Updated: 2024/04/03 12:19:35 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_pathfinder(int error_case, char **matrix, 
		t_er_map *error_map, char **matrix_copy)
{
	display_matrix(error_map->rc[0], error_map->rc[1], matrix_copy, 0);
	if (1 == error_case)
		ft_putstr_fd("Error: Malloc error in pathfinder.\n", 1);
	else if (2 == error_case)
		ft_putstr_fd("Error: Matrix duplication failed.\n", 1);
	else if (3 == error_case)
		ft_putstr_fd("Error: Map can't be completed.\n", 1);
	if (matrix_copy)
		free_matrix(error_map->rc[0], matrix_copy);
	if (4 == error_case)
		return ;
	if (matrix)
		free_matrix(error_map->rc[0], matrix);
	if (error_map)
		free(error_map);
	exit(EXIT_FAILURE);
}
