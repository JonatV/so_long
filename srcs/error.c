/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:11:15 by jveirman          #+#    #+#             */
/*   Updated: 2024/03/08 14:30:03 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error_exit(int error_case, int fd, char *mem, char *buf)
{
	if (1 == error_case)
	{
		//wip - msg
		exit(1);
	}
	if (2 == error_case)
	{
		//wip - msg
		close (fd);
		exit(1);
	}
	if (3 == error_case)
	{
		//wip - msg
		if (mem)
			free(mem);
		if (buf)
			free(buf);
		close (fd);
		exit(1);
	}
}