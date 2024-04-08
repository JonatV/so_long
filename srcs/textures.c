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

static int	set_textures_addr_2(t_game *game)
{
	game->mlx.sprite_w_tl = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_tl.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_w_tr = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_tr.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_w_bl = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_bl.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_w_br = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_br.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_w_t = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_t.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_w_b = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_b.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_w_l = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_l.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_w_r = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/w_r.xpm", &game->mlx.size, &game->mlx.size);
	if (!game->mlx.sprite_w_tr || !game->mlx.sprite_w_tr || \
	!game->mlx.sprite_w_bl || !game->mlx.sprite_w_br || \
	!game->mlx.sprite_w_t || !game->mlx.sprite_w_b || \
	!game->mlx.sprite_w_l || !game->mlx.sprite_w_r)
	{
		ft_printf("Error\nTextures failed to load.\n");
		return (0);
	}
	return (1);
}

int	set_textures_addr(t_game *game)
{
	game->mlx.sprite_ground = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/ground.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_block = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/block.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_collect = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/collect.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_exit = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/exit.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_player = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/player.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_exit_no = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/exit_no.xpm", &game->mlx.size, &game->mlx.size);
	game->mlx.sprite_win = mlx_xpm_file_to_image(game->mlx.mlx, \
"./textures/win.xpm", &game->mlx.size, &game->mlx.size);
	if (!game->mlx.sprite_ground || !game->mlx.sprite_block || \
	!game->mlx.sprite_collect || !game->mlx.sprite_exit || \
	!game->mlx.sprite_exit_no || !game->mlx.sprite_player || \
	!game->mlx.sprite_win)
	{
		ft_printf("Error\nTextures failed to load.\n");
		return (0);
	}
	return (set_textures_addr_2(game));
}

static void	*texture_wall(t_game *game, int x, int y)
{
	void	*ptr_texture;

	ptr_texture = NULL;
	if (0 == x && 0 == y)
		ptr_texture = game->mlx.sprite_w_tl;
	else if (game->cols - 1 == x && 0 == y)
		ptr_texture = game->mlx.sprite_w_tr;
	else if (0 == x && game->rows - 1 == y)
		ptr_texture = game->mlx.sprite_w_bl;
	else if (game->cols - 1 == x && game->rows - 1 == y)
		ptr_texture = game->mlx.sprite_w_br;
	else if (0 == x)
		ptr_texture = game->mlx.sprite_w_l;
	else if (game->cols - 1 == x)
		ptr_texture = game->mlx.sprite_w_r;
	else if (0 == y)
		ptr_texture = game->mlx.sprite_w_t;
	else if (game->rows - 1 == y)
		ptr_texture = game->mlx.sprite_w_b;
	return (ptr_texture);
}

static void	*texture_everything(t_game *game, int x, int y)
{
	void	*ptr_texture;

	if (game->map[y][x] == '1')
		ptr_texture = game->mlx.sprite_block;
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
	return (ptr_texture);
}

void	display_window(t_game *game, int x, int y)
{
	void	*ptr_texture;

	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (0 == y || game->rows - 1 == y || 0 == x || game->cols - 1 == x)
				ptr_texture = texture_wall(game, x, y);
			else
				ptr_texture = texture_everything(game, x, y);
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
			ptr_texture, game->mlx.size * x, game->mlx.size * y);
		}
	}
}
