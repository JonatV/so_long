/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:56:22 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/03 12:56:22 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_mlx_struct(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, \
	game->cols * SPRITE_SIZE, game->rows * SPRITE_SIZE, "so_long");
	mlx_hook(game->mlx.mlx_win, 17, 0, &quit, game);
	mlx_hook(game->mlx.mlx_win, 2, 1L << 0, key_listener, game);
}

static void	set_game_struct(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->collect++;
			else if (game->map[y][x] == 'P')
			{
				game->player_pos.x = x;
				game->player_pos.y = y;
			}
			x++;
		}
		y++;
	}
	game->rows = y;
	game->cols = x;
}

void	init_structs(t_game *game, char **map)
{
	game->map = map;
	game->collect = 0;
	game->inventory = 0;
	game->moves = 0;
	game->mlx.sprite_ground = 0;
	game->mlx.sprite_block = 0;
	game->mlx.sprite_w_tl = 0;
	game->mlx.sprite_w_tr = 0;
	game->mlx.sprite_w_bl = 0;
	game->mlx.sprite_w_br = 0;
	game->mlx.sprite_w_t = 0;
	game->mlx.sprite_w_b = 0;
	game->mlx.sprite_w_l = 0;
	game->mlx.sprite_w_r = 0;
	game->mlx.sprite_collect = 0;
	game->mlx.sprite_exit = 0;
	game->mlx.sprite_exit_no = 0;
	game->mlx.sprite_win = 0;
	game->mlx.sprite_player = 0;
	game->mlx.sprite_player_exit = 0;
	game->mlx.size = SPRITE_SIZE;
	set_game_struct(game);
	set_mlx_struct(game);
}
