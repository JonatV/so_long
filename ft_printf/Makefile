# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jveirman <jveirman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 17:44:13 by jveirman          #+#    #+#              #
#    Updated: 2024/01/21 17:55:39 by jveirman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I/includes/ft_printf.h
NAME 	=	libftprintf.a
SRCS	=	srcs/ft_printf.c srcs/ft_utils.c srcs/ft_putaddr.c \
			srcs/ft_puthex.c srcs/ft_putint.c srcs/ft_putuint.c
OBJS	=	${SRCS:.c=.o}
RM		=	rm -f
AR		=	ar rcs
.c.o	:
			${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
all		:	${NAME}
${NAME}	:	${OBJS}
			${AR} ${NAME} ${OBJS}
clean	:
			${RM} ${OBJS}
fclean	:	clean
			${RM} ${NAME}
re		:	fclean all

.PHONY	:	all clean fclean re