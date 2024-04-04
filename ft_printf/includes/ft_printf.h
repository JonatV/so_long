/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:49:57 by jveirman          #+#    #+#             */
/*   Updated: 2024/04/04 09:00:24 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putint(int num);
int		ft_putaddr(void *addr);
int		ft_putuint(unsigned int num);
int		ft_putbase(unsigned int num, char type, unsigned int base);
int		ft_printf(const char *str, ...);

size_t	ft_strlength(const char *str);
char	*ft_strchr(const char *str, int only);

#endif
