# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 18:06:59 by hakaddou          #+#    #+#              #
#    Updated: 2022/07/27 22:47:54 by hakaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= fdf.c valid_file_check.c parse_map.c mlx_test.c color_handle.c \
				  parse_cords.c bressen.c grids_and_points.c movements.c visuals.c \
				  key_hooks.c helpers_for_functions.c parse_cords2.c grid_points2.c \
				  grid_points3.c 

OBJS			= $(SRCS:.c=.o)

FLAGS			= -crs

mlx				= ./mlx/libmlx.a

LIBFT			= cd libft && make

LIB				= libft/libft.a

CC				= gcc -g3 -Ofast

RM				= rm -rf

CFLAGS			= -Wall -Wextra -Werror

VFLAGS			= --leak-check=full -s

NAME			= fdf

CLEAR_EXEC		= clear && ./$(NAME) hadi.fdf

CLEAR_EXECVAL	= clear && rm *.o && valgrind $(VFLAGS) ./$(NAME)

all:			$(NAME)

$(NAME):
				$(LIBFT)
				make -C ./mlx
				$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIB) $(mlx) -framework OpenGL -framework AppKit

clean:
				$(RM) $(OBJS)
				make clean -C ./mlx

fclean:			clean
				$(RM) $(NAME)
				make clean -C ./mlx

re:				fclean $(NAME)

exec:			fclean $(NAME)
				$(CLEAR_EXEC)

execval:		fclean $(NAME)
				$(CLEAR_EXECVAL)	

.PHONY:			all clean fclean re bonus
