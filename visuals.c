/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:25:51 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:54:23 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_2d_plane(t_fdf *fdf)
{
	fdf->x_start = 100;
	fdf->y_start = 100;
	redo_img(fdf);
	draw_cords(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}

void	reset_cords(t_fdf *fdf)
{
	fdf->grid_x = WIND_BORDER / fdf->width;
	fdf->grid_y = WIND_BORDER / fdf->height;
	fdf->grid = return_smaller_grid(fdf);
	fdf->x_start = XSTART;
	fdf->y_start = YSTART;
	fdf->y_to = fdf->y_start;
	fdf->x_to = fdf->x_start;
	fdf->zoom_tracker = 0;
	fdf->fixed_grid = return_smaller_grid(fdf);
	fdf->fixed_start_x = 600;
	fdf->fixed_start_y = 300;
}

void	redraw_3d(t_fdf *fdf)
{
	redo_img(fdf);
	reset_cords(fdf);
	draw_isometric(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}

void	mesh_them(t_fdf *fdf, int key)
{
	int	i;

	i = -1;
	if (key == NMESH)
	{
		redo_img(fdf);
		draw_isometric_s(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
		return ;
	}
	redo_img(fdf);
	while (++i < 3)
	{
		fdf->fixed_start_x += 4;
		fdf->fixed_start_y += 4;
		draw_isometric_s(fdf);
	}
	i = -1;
	while (++i < 3)
	{
		fdf->fixed_start_x -= 4;
		fdf->fixed_start_y -= 4;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}
