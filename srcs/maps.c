/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:58:44 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/10 17:07:37 by ventouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_set_data(char *map_to_str, int i, int *rc, int temp_length)
{
	while (map_to_str[i])
	{
		if (!is_char_valid(map_to_str[i++]))
			ft_error_reading_1(1, map_to_str);
	}
	rc[0] = 0;
	rc[1] = -1;
	i = 0;
	while (map_to_str[i])
	{
		if (map_to_str[i++] == '\n')
		{
			rc[0]++;
			if (-1 == rc[1])
				rc[1] = temp_length;
			else if (temp_length != rc[1])
				ft_error_reading_1(2, map_to_str);
			temp_length = 0;
		}
		else
			temp_length++;
	}
	return (1);
}

int	map_reading(char *map_path, char **map_gnl, int *rc)
{
	int		fd;
	int		nbr_bytes;
	char	*buf;
	char	*temp;
	
	temp = "";
	*map_gnl = "";
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_reading(1, fd, NULL, NULL);
	buf = (char *)malloc(sizeof(char));
	if (!buf)
		ft_error_reading(2, fd, NULL, NULL);
	nbr_bytes = read(fd, buf, 1);
	while (nbr_bytes > 0)
	{
		temp = ft_strjoin(temp, buf);
		if (!temp)
			ft_error_reading(3, fd, *map_gnl, buf);
		*map_gnl = temp;
		nbr_bytes = read(fd, buf, 1);
	}
	free(buf);
	close(fd);
	return (check_set_data(*map_gnl, 0, rc, 0));
}

static void	fill_requisities(t_er_map *error_map, char *map_gnl, int *rc)
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

static void	check_requisities(t_er_map *error_map, char *map_gnl)
{
	if (error_map->size == 1)
		ft_error_map(1, map_gnl, error_map);
	if (error_map->size == 2)
		ft_error_map(2, map_gnl, error_map);
	if (error_map->collect < 1)
		ft_error_map(3, map_gnl, error_map);
	if (error_map->start != 1)
		ft_error_map(4, map_gnl, error_map);
	if (error_map->exit != 1)
		ft_error_map(5, map_gnl, error_map);
}

static void	create_matrix(t_er_map *error_map, char *map_gnl, int *rc, char ***the_grid)
{
	int	i;
	int	j;
	int k;

	*the_grid = (char **)malloc(sizeof(char *) * rc[0]);
	if (*the_grid == NULL)
		ft_error_map_1(rc, map_gnl, error_map, NULL); //wip
	i = 0;
	k = 0;
	while (i < rc[0])
	{

		(*the_grid)[i] = (char *)malloc(rc[1] * sizeof(char));
		if ((*the_grid)[i] == NULL)
			ft_error_map_1(rc, map_gnl, error_map, *the_grid);
		j = 0;
		while (j < rc[1])
			(*the_grid)[i][j++] = map_gnl[k++];
		k++;
		i++;
	}
}

void displayMatrix(int rows, int cols, char **matrix) //debug function
{
	int i;
	int j;

	printf("\n");
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
			printf("%c", matrix[i][j++]);
		printf("\n");
		i++;
	}
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
	return (ft_error_map_2(t_b_l_r));
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
	fill_requisities(error_map, map_gnl, rc);
	check_requisities(error_map, map_gnl);
	create_matrix(error_map, map_gnl, rc, the_grid);
	displayMatrix(rc[0], rc[1], *the_grid);//debug
	if (!check_extremities(rc, *the_grid, 0, (int[]){0, 0, 0, 0}))
	{
		free_matrix(rc[0], *the_grid);
		free(map_gnl);
		free(error_map);
		exit(EXIT_FAILURE);
	}
	pathfinder(rc, the_grid, error_map);
	free(error_map);
}
