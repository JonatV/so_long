/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:48:42 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/08 16:42:50 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h" //debug
#include <stdio.h> //debug
#include <stdlib.h> //debug
#include <unistd.h> //debug
#include <fcntl.h> //debug

//----------- MAP
int	map_reading(char *map_path);

//----------- ERROR
void error_exit(int error_case, int fd, char *mem, char *buf);

//----------- ERROR_UTILS
int	is_char_valid(int c);

#endif