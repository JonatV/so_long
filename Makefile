NAME		=	so_long

SRCDIR		=	srcs/
LIBFT		=	./libft/libft.a
INCLUDE		=	-I./includes/so_long.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
RM			=	rm -rf
ARCH_FLAGS	=	ar -rcs

SRC			=	$(SRCDIR)so_long.c	\
				$(SRCDIR)maps.c		\
				$(SRCDIR)maps_utils.c \
				$(SRCDIR)error.c	\
				$(SRCDIR)error_pathfinder.c	\
				$(SRCDIR)error_utils.c

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(LIBFT):
				make -C ./libft

$(NAME):		$(LIBFT) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT) -o $@ 

%.o:			%.c
				$(CC) $(CFLAGS) -c $^ -o $@

clean :			
				$(RM) $(OBJ)
				make clean -C ./libft

fclean :		clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)


re :			fclean all

.PHONY: all clean fclean re