/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:58:44 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/08 17:02:41 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_set_data(char *map_to_str, int i)
{
	while (map_to_str[i])
	{
		if (!is_char_valid(map_to_str[i]))
			// error_exit()
		// stopped here, i should decide if it is better to start calculating the collectible, P, C, E, col row, etc 
		// Or if it is better to create the matrix and checking all the Char and the border if it is wall, if it is rectangle etc
		// And it's time to thing about the main game struct.
		// Try to see if it is interresting to have a struct with x and y to load coordinate from the main elements (E,P,C)
		i++;
	}
}

int	map_reading(char *map_path)
{
	int		fd;
	int		nbr_bytes;
	char	*buf;
	char	*map_to_str;
	char	*temp;
	
	temp = "";
	map_to_str = ""; //wip, will be initialised in the main structure
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
			error_exit(3, fd, map_to_str, buf);
		map_to_str = temp;
		nbr_bytes = read(fd, buf, 1);
	}
	close(fd);
	return (check_set_data(map_to_str, 0));
}
