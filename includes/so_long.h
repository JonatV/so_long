/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ventouse <ventouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:48:42 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/09 18:44:21 by ventouse         ###   ########.fr       */
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
	bool	wall;
	int		collect;
}	t_er_map;

typedef struct s_game
{
	int		collect;
}	t_game;
//----------- MAP
int		map_reading(char *map_path, char **map_gnl, int *rc);
void	**build_matrix(char *map_gnl, int *rc);

//----------- ERROR
void	error_exit(int error_case, int fd, char *mem, char *buf);

//----------- ERROR_UTILS
int		is_char_valid(int c);

#endif