/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:37 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/12 14:13:14 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_matrix(int rows, int cols, char **matrix, int is_before)
{
	int	i;
	int	j;

	printf("\n");
	if (is_before)
		printf("Map received :\n");
	else
		printf("Algo has access to all the \"-\" :\n");
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

int	main(int argc, char **argv)
{
	char	*map_gnl;
	char	**the_grid;
	int		rc[2];

	if (2 != argc)
	{
		ft_putstr_fd("Error: Input should looks like: ", 1);
		ft_putstr_fd("./so_long <map_path.ber>\n", 1);
		return (0);
	}
	if (is_file_valid(argv[1]) && map_reading(argv[1], &map_gnl, rc))
		build_matrix(map_gnl, rc, &the_grid);
	return (0);
}
