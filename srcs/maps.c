/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:58:44 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/12 13:26:25 by jveirman         ###   ########.fr       */
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
		ft_error_maps(1, fd, NULL, NULL);
	buf = (char *)malloc(sizeof(char));
	if (!buf)
		ft_error_maps(2, fd, NULL, NULL);
	nbr_bytes = read(fd, buf, 1);
	while (nbr_bytes > 0)
	{
		temp = ft_strjoin(temp, buf);
		if (!temp)
			ft_error_maps(3, fd, *map_gnl, buf);
		*map_gnl = temp;
		nbr_bytes = read(fd, buf, 1);
	}
	free(buf);
	close(fd);
	return (check_set_data(*map_gnl, 0, rc, 0));
}
