/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:48:42 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/04 10:49:42 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define SPRITE_SIZE 64

# define U	13
# define D	1
# define L	0
# define R	2

# define A_U	126
# define A_D	125
# define A_L	123
# define A_R	124

# define EXIT	53

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*sprite_ground;
	void	*sprite_wall;
	void	*sprite_collect;
	void	*sprite_exit;
	void	*sprite_exit_no;
	void	*sprite_win;
	void	*sprite_player;
	void	*sprite_player_exit;
	void	*bg;
	int		size;
}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	char	**map;
	int		rows;
	int		cols;
	int		collect;
	int		inventory;
	int		moves;
	t_pos	player_pos;
}	t_game;

typedef struct s_error_map
{
	int		exit;
	int		start;
	int		size;
	int		collect;
	int		rc[2];
}	t_er_map;

typedef struct s_algo_result
{
	int		exit;
	int		collect;
}	t_algo_res;

void	display_window(t_game *game, int x, int y);
void	game_to_display(t_game *game);

// ----------- HOOKS
int		key_listener(int key, t_game *game);
int		quit(t_game *game, int value);

// ----------- STRUCT
void	init_structs(t_game *game, char **map);

// ----------- MOUVEMENT
void	move_player(t_game *game, int key);

// ----------- TEXTURES
int		set_textures_addr(t_game *game);

//----------- ERROR_MAPS
void	ft_error_maps(int error_case, int fd, char *mem);
void	ft_error_maps_1(int error_case, char *mem);

//----------- ERROR_MATRIX
void	ft_error_matrix(int error_case, char *map_gnl, t_er_map *error_map);
void	ft_error_matrix_1(int *rc, char *map_gnl, \
		t_er_map *error_map, char **matrix);
int		ft_error_matrix_2(int t_b_l_r[4]);

//----------- ERROR_PATHFINDER
void	ft_error_pathfinder(int error_case, char **matrix, \
		t_er_map *error_map, char **matrix_copy);

//----------- ERROR_UTILS
int		is_file_valid(char *str);
int		is_char_valid(int c);
void	free_matrix(int rows, char **matrix);

//----------- PATHFINDER
void	pathfinder(int *rc, char ***matrix, t_er_map *er_map);

//----------- MATRIX
void	build_matrix(char *map_gnl, int *rc, char ***the_grid);

//----------- MAPS
int		map_reading(char *map_path, char **map_gnl, int *rc);

#endif
