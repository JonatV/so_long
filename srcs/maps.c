/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:58:44 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/09 18:52:39 by ventouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_set_data(char *map_to_str, int i, int *rc)
{
	while (map_to_str[i])
	{
		if (!is_char_valid(map_to_str[i]))
		{
			printf("Wrong char\n");
			exit(EXIT_FAILURE); // wip
		}
		i++;
	}
	rc[0] = 0;
	rc[1] = -1;
	i = 0;
	while (map_to_str[i])
	{
		if (map_to_str[i] == '\n')
		{
			rc[0]++;
			if (-1 == rc[1])
				rc[1] = i;
		}
		i++;
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
		error_exit(1, fd, NULL, NULL);
	buf = (char *)malloc(sizeof(char));
	if (!buf)
		error_exit(2, fd, NULL, NULL);
	nbr_bytes = read(fd, buf, 1);
	while (nbr_bytes > 0)
	{
		temp = ft_strjoin(temp, buf);
		if (!temp)
			error_exit(3, fd, *map_gnl, buf);
		*map_gnl = temp;
		nbr_bytes = read(fd, buf, 1);
	}
	close(fd);
	return (check_set_data(*map_gnl, 0, rc));
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
	}
	if (rc[0] == rc[1])
		error_map->wall = true;
	else if (rc[0] < 3 && rc[1] < 4)
		error_map->wall = true;
	else if (rc[0] < 4 && rc[1] < 3)
		error_map->wall = true;
	else
		error_map->wall = false;
}

void	**build_matrix(char *map_gnl, int *rc)
{
	t_er_map	*error_map;

	error_map = malloc (sizeof(t_er_map));
	error_map->collect = 0;
	error_map->exit = 0;
	error_map->start = 0;
	error_map->wall = false;
	fill_requisities(error_map, map_gnl, rc);
	//alloc_matrix();
}