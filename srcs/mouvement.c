/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:56:19 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/03 12:56:19 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moves_update(t_game *game)
{
	game->moves++;
	printf("Moves : [%d]\n", game->moves);
}

void	update_game_state(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'X')
		printf("You Win!\nWith [%d] moves", game->moves);
}

int	is_move_valid(t_game *game, int next_x, int next_y)
{
	if (game->map[next_y][next_x] == '1')
	{
		printf("HIT WALL\n");
		return (0);
	}
	if (game->map[next_y][next_x] == 'C')
	{
		printf("HIT COLLECT\n");
		game->inventory++;
	}

	if (game->map[next_y][next_x] == 'E')
	{
		printf("ON THE EXIT\n");
		if (game->inventory == game->collect)
			game->map[next_y][next_x] = 'X';
		else
			game->map[next_y][next_x] = 'W';
	}
	else
	{
		game->map[next_y][next_x] = 'P';

	}
	if (game->map[game->player_pos.y][game->player_pos.x] == 'W')
		game->map[game->player_pos.y][game->player_pos.x] = 'E';
	else
		game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.x = next_x;
	game->player_pos.y = next_y;
	return (1);
}

void	move_player(t_game *game, int key)
{
	int	x;
	int	y;
	
	x = game->player_pos.x;
	y = game->player_pos.y;
	if (game->map[y][x] == 'X') // this means your on the exit +
		return ;
	if (key == U || key == A_U)
	{
		if (is_move_valid(game, x, y - 1) == 0)
			return ;
	}
	else if (key == D || key == A_D)
	{
		if (is_move_valid(game, x, y + 1) == 0)
			return ;
	}
	else if (key == L || key == A_L)
	{
		if (is_move_valid(game, x - 1, y) == 0)
			return ;
	}
	else if (key == R || key == A_R)
	{
		if (is_move_valid(game, x + 1, y) == 0)
			return ;
	}
	moves_update(game);
	display_window(game);
	update_game_state(game, game->player_pos.x, game->player_pos.y);
}

