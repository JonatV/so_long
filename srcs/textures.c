/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:56:25 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/03 12:56:25 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_textures_addr(t_game *game)
{
	game->mlx.sprite_ground = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/ground.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_wall = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/wall.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_collect = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/collect.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_exit = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/exit.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_player = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/player.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_exit_no = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/exit_no.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_win = mlx_xpm_file_to_image(game->mlx.mlx, "./textures/win.xpm", &game->mlx.size, &game->mlx.size);
	if(!game->mlx.sprite_ground || !game->mlx.sprite_wall || !game->mlx.sprite_collect || !game->mlx.sprite_exit || !game->mlx.sprite_exit_no|| !game->mlx.sprite_player || !game->mlx.sprite_win)
	{
		printf("Error : Textures failed to load.\n");
		return (0);
	}
	return (1);
}

void	display_window(t_game *game)
{
	int		x;
	int		y;
	void	*ptr_texture;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				ptr_texture = game->mlx.sprite_wall;
			else if (game->map[y][x] == 'C')
				ptr_texture = game->mlx.sprite_collect;
			else if (game->map[y][x] == 'E')
				ptr_texture = game->mlx.sprite_exit;
			else if (game->map[y][x] == 'P')
				ptr_texture = game->mlx.sprite_player;
			else if (game->map[y][x] == 'W')
				ptr_texture = game->mlx.sprite_exit_no;
			else if (game->map[y][x] == 'X')
				ptr_texture = game->mlx.sprite_win;
			else
				ptr_texture = game->mlx.sprite_ground;
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, ptr_texture, game->mlx.size * x, game->mlx.size * y);
		}
	}
}
