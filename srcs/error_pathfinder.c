/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pathfinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:29:40 by ventouse          #+#    #+#             */
/*   Updated: 2024/04/08 15:58:24 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_pathfinder(int error_case, char **matrix,
		t_er_map *error_map, char **matrix_copy)
{
	if (1 == error_case)
		ft_putstr_fd("Error\nMalloc error in pathfinder.\n", 1);
	else if (2 == error_case)
		ft_putstr_fd("Error\nMatrix duplication failed.\n", 1);
	else if (3 == error_case)
		ft_putstr_fd("Error\nMap can't be completed.\n", 1);
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
