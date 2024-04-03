/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:58:44 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/03 11:17:12 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_set_data(char *map_to_str, int i, int *rc, int temp_length)
{
	while (map_to_str[i])
	{
		if (!is_char_valid(map_to_str[i++]))
			ft_error_maps_1(1, map_to_str);
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
				ft_error_maps_1(2, map_to_str);
			temp_length = 0;
		}
		else
			temp_length++;
	}
	// printf("Return 1 from map_reading process\n"); // debug
	return (1);
}

// int	map_reading(char *map_path, char **map_gnl, int *rc)
// {
// 	int		fd;
// 	int		nbr_bytes;
// 	char	buf[2];
// 	char	*temp;

// 	// temp = "";
// 	temp = NULL;
// 	// *map_gnl = "";
// 	fd = open(map_path, O_RDONLY);
// 	if (fd < 0)
// 		ft_error_maps(1, fd, NULL);
// 	buf[0] = '\0';
// 	buf[1] = '\0';
// 	nbr_bytes = read(fd, buf, 1);
// 	int i = 0; // debug
// 	while (nbr_bytes > 0)
// 	{
// 		*map_gnl = ft_strjoin(temp, buf);
// 		if (!*map_gnl)
// 			ft_error_maps(3, fd, *map_gnl);
// 		temp = *map_gnl;
// 		if (*map_gnl)
// 			free(*map_gnl);
// 		nbr_bytes = read(fd, buf, 1);
// 		printf("[%d]\n", i++);
// 		printf("%s\n", *map_gnl);
// 	}
// 	close(fd);
// 	return (check_set_data(*map_gnl, 0, rc, 0));
// }

int	map_reading(char *map_path, char **map_gnl, int *rc)
{
	int		fd;
	int		nbr_bytes;
	char	buf[2];
	char	*temp = NULL;
	char	*old_temp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_maps(1, fd, NULL);
	buf[0] = '\0';
	buf[1] = '\0';
	nbr_bytes = read(fd, buf, 1);
	// int i = 0; // debug
	while (nbr_bytes > 0)
	{
		old_temp = temp; // Save old pointer
		temp = ft_strjoin(temp, buf); // Concatenate
		free(old_temp); // Free old temp
		if (!temp)
			ft_error_maps(3, fd, temp);
		nbr_bytes = read(fd, buf, 1);
		// printf("[%d]\n", i++);
		// printf("%s\n", temp);
	}
	*map_gnl = temp;
	close(fd);
	return (check_set_data(*map_gnl, 0, rc, 0));
}
