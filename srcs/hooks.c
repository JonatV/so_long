/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:56:13 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/03 12:56:13 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit(1);
}

int	key_listener(int key, t_game *game)
{
	if (key == EXIT)
		quit(game);
	if (key == U || key == D || key == L || key == R || key == A_U || key == A_D || key == A_L || key == A_R)
	{
		move_player(game, key);
	}
	return (0);
}
