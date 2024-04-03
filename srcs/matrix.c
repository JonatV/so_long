/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:00:25 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/03 14:41:39 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	fill_requisites(t_er_map *error_map, char *map_gnl, int *rc)
{
	int	i;

	i = 0;
	while (map_gnl[i])
	{
		if (map_gnl[i] == 'P')
			error_map->start++;
		if (map_gnl[i] == 'E')
			error_map->exit++;
		if (map_gnl[i] == 'C')
			error_map->collect++;
		i++;
	}
	if (rc[0] == rc[1])
		error_map->size = 1;
	else if (rc[0] == 3 && rc[1] < 5)
		error_map->size = 2;
	else if (rc[0] < 5 && rc[1] == 3)
		error_map->size = 2;
}

static void	check_requisites(t_er_map *error_map, char *map_gnl)
{
	if (error_map->size == 1)
		ft_error_matrix(1, map_gnl, error_map);
	if (error_map->size == 2)
		ft_error_matrix(2, map_gnl, error_map);
	if (error_map->collect < 1)
		ft_error_matrix(3, map_gnl, error_map);
	if (error_map->start != 1)
		ft_error_matrix(4, map_gnl, error_map);
	if (error_map->exit != 1)
		ft_error_matrix(5, map_gnl, error_map);
}

static void	create_matrix(t_er_map *error_map, char *map_gnl, 
			int *rc, char ***the_grid)
{
	int	i;
	int	j;
	int	k;

	*the_grid = (char **)malloc(sizeof(char *) * rc[0] + 1);
	if (*the_grid == NULL)
		ft_error_matrix_1(rc, map_gnl, error_map, NULL);
	i = 0;
	k = 0;
	while (i < rc[0])
	{
		(*the_grid)[i] = (char *)malloc(rc[1] * sizeof(char));
		if ((*the_grid)[i] == NULL)
			ft_error_matrix_1(rc, map_gnl, error_map, *the_grid);
		j = 0;
		while (j < rc[1])
			(*the_grid)[i][j++] = map_gnl[k++];
		(*the_grid)[i][j] = '\0';
		k++;
		i++;
	}
	(*the_grid)[i] = NULL;
}

static int	check_extremities(int rc[2], char **matrix, int i, int t_b_l_r[4])
{
	while (i < rc[1])
	{
		if (matrix[0][i] != '1')
			t_b_l_r[0]++;
		if (matrix[rc[0] - 1][i] != '1')
			t_b_l_r[1]++;
		i++;
	}
	i = 0;
	while (i < rc[0])
	{
		if (matrix[i][0] != '1')
			t_b_l_r[2]++;
		if (matrix[i][rc[1] - 1] != '1')
			t_b_l_r[3]++;
		i++;
	}
	return (ft_error_matrix_2(t_b_l_r));
}

void	build_matrix(char *map_gnl, int *rc, char ***the_grid)
{
	t_er_map	*error_map;

	error_map = malloc (sizeof(t_er_map));
	error_map->collect = 0;
	error_map->exit = 0;
	error_map->start = 0;
	error_map->size = 0;
	error_map->rc[0] = rc[0];
	error_map->rc[1] = rc[1];
	fill_requisites(error_map, map_gnl, rc);
	check_requisites(error_map, map_gnl);
	create_matrix(error_map, map_gnl, rc, the_grid);
	free(map_gnl); // info - not needed anymore
	display_matrix(rc[0], rc[1], *the_grid, 1); // debug
	if (!check_extremities(rc, *the_grid, 0, (int []){0, 0, 0, 0}))
	{
		free_matrix(rc[0], *the_grid);
		free(map_gnl);
		free(error_map);
		exit(EXIT_FAILURE);
	}
	pathfinder(rc, the_grid, error_map);
	free(error_map);
}
