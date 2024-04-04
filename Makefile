NAME		=	so_long

SRCDIR		=	srcs/
LIBFT		=	./libft/libft.a
PRINTF		=	./ft_printf/libftprintf.a
INCLUDE		=	-I./includes/so_long.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -rf
ARCH_FLAGS	=	ar -rcs

SRC			=	$(SRCDIR)so_long.c	\
				$(SRCDIR)maps.c		\
				$(SRCDIR)matrix.c \
				$(SRCDIR)pathfinder.c \
				$(SRCDIR)error_maps.c	\
				$(SRCDIR)error_matrix.c	\
				$(SRCDIR)error_pathfinder.c	\
				$(SRCDIR)error_utils.c \
				$(SRCDIR)hooks.c \
				$(SRCDIR)mouvement.c \
				$(SRCDIR)struct.c \
				$(SRCDIR)textures.c

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(LIBFT):		
				make -C ./libft

$(PRINTF):		
				make -C ./ft_printf
				

$(NAME):		$(LIBFT) $(PRINTF) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(MLX_FLAGS) $(LIBFT) $(PRINTF) -o $@

%.o:			%.c
				$(CC) $(CFLAGS) -c $^ -o $@

clean :			
				$(RM) $(OBJ)
				make clean -C ./libft
				make clean -C ./ft_printf

fclean :		clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)
				$(RM) $(PRINTF)

re :			fclean all

.PHONY: all clean fclean re
