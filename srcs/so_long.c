/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:37 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/04 10:50:13 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_to_display(t_game *game)
{
	if (!set_textures_addr(game))
		quit(game, EXIT_FAILURE);
	display_window(game, -1, -1);
}

int	main(int argc, char **argv)
{
	char	*map_gnl;
	char	**the_grid;
	int		rc[2];
	t_game	game;

	the_grid = NULL;
	map_gnl = NULL;
	if (2 != argc)
	{
		ft_putstr_fd("Error: Input should looks like: ", 1);
		ft_putstr_fd("./so_long <map_path.ber>\n", 1);
		return (0);
	}
	if (is_file_valid(argv[1]) && map_reading(argv[1], &map_gnl, rc))
		build_matrix(map_gnl, rc, &the_grid);
	init_structs(&game, the_grid);
	game_to_display(&game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
