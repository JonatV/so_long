/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:48:42 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/12 16:22:50 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h> //debug
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> //debug

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

typedef struct s_game
{
	int		collect;
}	t_game;

//----------- DEBUG FUNTIONS
void	display_matrix(int rows, int cols, char **matrix, int is_before); //debug function

//----------- ERROR_MAPS
void	ft_error_maps(int error_case, int fd, char *mem);
void	ft_error_maps_1(int error_case, char *mem);

//----------- ERROR_MATRIX
void	ft_error_matrix(int error_case, char *map_gnl, t_er_map *error_map);
void	ft_error_matrix_1(int *rc, char *map_gnl, t_er_map *error_map, char **matrix);
int		ft_error_matrix_2(int t_b_l_r[4]);

//----------- ERROR_PATHFINDER
void	ft_error_pathfinder(int error_case, char **matrix, t_er_map *error_map, char **matrix_copy);

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