/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:16:37 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 23:00:11 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <time.h>

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/errno.h>
# include <string.h>
# include <stdarg.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define WINDOW_SIZE 1400
# define WIND_BORDER 1200
# define XSTART 600
# define YSTART 300

/*	Keys	*/
# define ESC 53
# define LEFT_AROW 123
# define RIGHT_AROW 124
# define DOWN_AROW 125
# define UP_AROW 126
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define ONE 18
# define TWO 19
# define THREE 20
# define LOOP 37
# define W_KEY 13
# define D_KEY 2
# define S_KEY 1
# define A_KEY 0
# define MESH 46
# define NMESH 45
# define REDO 666
# define Z_KEY 6
# define X_KEY 7

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct t_fdf
{
	int		fd;
	int		line_count;
	char	*file;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	***cords;
	int		width;
	int		height;
	int		x_start;
	int		x_to;
	int		y_start;
	int		y_to;
	int		grid_x;
	int		grid_y;
	int		grid;
	int		x[2];
	int		y[2];
	int		color;
	int		xmover;
	int		ymover;
	int		zoom_tracker;
	int		fixed_grid;
	int		fixed_start_x;
	int		fixed_start_y;
	int		z[1000][1000];
	int		z_b[1000][1000];
}				t_fdf;

void	check_validity(int ac, char **av);

void	error_and_exit(int flag, t_fdf *fdf);

void	check_dot_fdf(char *str);

void	free_map(t_fdf *fdf);

void	count_lines(t_fdf *fdf);

void	print_map(t_fdf *fdf);

void	parse_map(t_fdf *fdf);

void	check_map_length(t_fdf *fdf);

void	ft_open_and_parse(t_fdf *fdf, char *file);

void	init_check_open_parse(int ac, char **av, t_fdf *fdf);

/* Prase coordinates	*/
void	parse_cords(t_fdf *fdf);

void	check_empty(t_fdf *fdf);

int		count_bytes(t_fdf *fdf);

void	print_cords(t_fdf *fdf);

void	free_cords(t_fdf *fdf);

void	free_split(char **split);

void	check_cords(t_fdf *fdf);

/*	mlx tests	*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	draw_triangle(t_fdf *fdf, int x, int y, int color);

/*	color handeling	*/
long	convert_color(char *str);

/*	bressenhams algo	*/
void	ft_drawlinex(t_fdf *fdf);

void	ft_drawliney(t_fdf *fdf);

void	iso_set_points(t_fdf *fdf, int *grid, int flag, int i);

void	draw(t_fdf *fdf);

/*	draws the square	*/
void	draw_border(t_fdf *fdf);

/* 	puts img to window, frees cords and loops	*/
void	put_img_free(t_fdf *fdf);

void	redo_img(t_fdf *fdf);

void	destroy_win_imf_free(t_fdf *fdf);

int		exit_app(t_fdf *fdf);

void	init_win_img_pixil(t_fdf *fdf);

/*	keey hooks	*/
int		keys_handler(int key, t_fdf *fdf);

/*	visual effects	*/
void	mesh_them(t_fdf *fdf, int key);

void	redraw_3d(t_fdf *fdf);

void	draw_2d_plane(t_fdf *fdf);

void	shift_cords(int key, t_fdf *fdf);

int		return_smaller_grid(t_fdf *fdf);

void	draw_isometric(t_fdf *fdf);

void	draw_cords(t_fdf *fdf);

long	conv_color2(int i, int j, t_fdf *fdf);

/*	grids and points	*/
int		return_zoom_grid_ratio(t_fdf *fdf, int key);

void	draw_isometric_s(t_fdf *fdf);

void	set_xy_point(t_fdf *fdf, int flag);

int		z_conv(int z, int grid);

int		return_smaller_grid(t_fdf *fdf);

void	ft_swap(int *a, int *b);

void	reset_z(t_fdf *fdf);

#endif