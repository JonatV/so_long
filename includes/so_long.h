/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:48:42 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/10 03:16:27 by ventouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h" //debug
#include <stdio.h> //debug
#include <stdlib.h> //debug
#include <unistd.h> //debug
#include <fcntl.h> //debug

typedef enum { false, true } bool;

typedef struct s_error_map
{
	int		exit;
	int		start;
	int		size;
	int		collect;
}	t_er_map;

typedef struct s_game
{
	int		collect;
}	t_game;

//----------- ERROR
void	ft_error_reading(int error_case, int fd, char *mem, char *buf);
void	ft_error_reading_1(int error_case, char *mem);
void	ft_error_map(int error_case, char *map_gnl, t_er_map *error_map);
void	ft_error_map_1(int *rc, char *map_gnl, t_er_map *error_map, char **matrix);

//----------- ERROR_UTILS
int		is_char_valid(int c);
void	free_matrix(int *rc, char **matrix);

//----------- MAP
int		map_reading(char *map_path, char **map_gnl, int *rc);
void	build_matrix(char *map_gnl, int *rc, char ***the_grid);

#endif