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

static int	is_move_valid(t_game *game, int next_x, int next_y)
{
	if (game->map[next_y][next_x] == '1')
		return (0);
	if (game->map[next_y][next_x] == 'C')
		game->inventory++;
	if (game->map[next_y][next_x] == 'E')
	{
		if (game->inventory == game->collect)
			game->map[next_y][next_x] = 'X';
		else
			game->map[next_y][next_x] = 'W';
	}
	else
		game->map[next_y][next_x] = 'P';
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
	int	next_x;
	int	next_y;

	next_x = 0;
	next_y = 0;
	if (game->map[game->player_pos.y][game->player_pos.x] == 'X')
		return ;
	if (key == U || key == A_U)
		next_y = -1;
	else if (key == D || key == A_D)
		next_y = 1;
	else if (key == L || key == A_L)
		next_x = -1;
	else if (key == R || key == A_R)
		next_x = 1;
	if (!is_move_valid(game, game->player_pos.x + next_x, \
	game->player_pos.y + next_y))
		return ;
	game->moves++;
	ft_printf("Moves : [%d]\n", game->moves);
	display_window(game, -1, -1);
	if (game->map[game->player_pos.y][game->player_pos.x] == 'X')
		ft_printf("You Win!\nWith [%d] moves", game->moves);
}
