/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:37 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/10 03:27:17 by ventouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	char	*map_gnl;
	char	**the_grid;
	int		rc[2];

	if (2 != argc)
	{
		printf("Error\nInput should looks like: ./so_long <map_path.ber>\n"); // wip - 
		return (0);
	}
	if (map_reading(argv[1], &map_gnl, rc))
	{
		build_matrix(map_gnl, rc, &the_grid);
	}
	return (0);
}
