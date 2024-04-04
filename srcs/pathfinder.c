/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:09:55 by ventouse          #+#    #+#             */
/*   Updated: 2024/04/04 09:30:38 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_copy_matrix(int rows, int cols, char **matrix)
{
	int		i;
	int		j;
	char	**copy;

	copy = malloc(sizeof(char *) * rows);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = malloc(sizeof(char) * (cols + 1));
		if (!copy[i])
		{
			free_matrix(rows, copy);
			return (NULL);
		}
		j = 0;
		while (j < cols)
		{
			copy[i][j] = matrix[i][j];
			j++;
		}
		copy[i++][j] = '\0';
	}
	return (copy);
}

static void	find_pos_index(int *rc, char **matrix, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < rc[0])
	{
		j = 0;
		while (j < rc[1])
		{
			if (matrix[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	algo_floodfill(char **matrix, int x, int y, t_algo_res *algo_res)
{
	if (matrix[x][y] == '1' || matrix[x][y] == '-')
		return ;
	if (matrix[x][y] == 'C')
		algo_res->collect++;
	else if (matrix[x][y] == 'E')
		algo_res->exit++;
	matrix[x][y] = '-';
	algo_floodfill(matrix, x + 1, y, algo_res);
	algo_floodfill(matrix, x - 1, y, algo_res);
	algo_floodfill(matrix, x, y + 1, algo_res);
	algo_floodfill(matrix, x, y - 1, algo_res);
}

void	pathfinder(int *rc, char ***matrix, t_er_map *er_map)
{
	char		**matrix_copy;
	int			start_x;
	int			start_y;
	t_algo_res	*algo_res;

	algo_res = malloc(sizeof(t_algo_res));
	if (!algo_res)
		ft_error_pathfinder(1, *matrix, er_map, NULL);
	algo_res->collect = 0;
	algo_res->exit = 0;
	matrix_copy = ft_copy_matrix(rc[0], rc[1], *matrix);
	if (!matrix_copy)
	{
		free(algo_res);
		ft_error_pathfinder(2, *matrix, er_map, NULL);
	}
	find_pos_index(rc, matrix_copy, &start_x, &start_y);
	algo_floodfill(matrix_copy, start_x, start_y, algo_res);
	if (er_map->collect != algo_res->collect || er_map->exit != algo_res->exit)
	{
		free(algo_res);
		ft_error_pathfinder(3, *matrix, er_map, matrix_copy);
	}
	free(algo_res);
	ft_error_pathfinder(4, *matrix, er_map, matrix_copy);
}
