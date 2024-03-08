/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:11:37 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/08 13:52:38 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	(void)argv;
	if (2 != argc)
	{
		printf("Error\nInput should looks like: ./so_long <map_path.ber>\n"); // wip - 
		return (0);
	}
	if (0 == map_reading(argv[1]))
		return (1);
	return (0);
}
