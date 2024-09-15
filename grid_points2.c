/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_points2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:45:23 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:46:08 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	return_smaller_grid(t_fdf *fdf)
{
	if (fdf->grid_x > fdf->grid_y)
		return (fdf->grid_y);
	else
		return (fdf->grid_x);
}

void	set_xy_point(t_fdf *fdf, int flag)
{
	if (flag == 0)
	{	
		fdf->x_start = 100;
		fdf->y_to = fdf->y_start;
		fdf->x_to = fdf->x_start;
	}
	if (flag == 1)
		fdf->x_start = fdf->x_to;
}

void	init_points_2d(t_fdf *fdf, int flag, int grid)
{
	if (flag == 1)
	{
		fdf->x[0] = fdf->x_start;
		fdf->y[0] = fdf->y_start;
		fdf->x[1] = fdf->x_to;
		fdf->y[1] = fdf->y_to;
	}
	else
	{
		fdf->x[0] = fdf->x_start;
		fdf->y[0] = fdf->y_start + grid;
		fdf->x[1] = fdf->x_to - grid;
		fdf->y[1] = fdf->y_to;
	}
}

void	draw_cords_helper(t_fdf *fdf, int *grid)
{
	if (fdf->grid_x > fdf->grid_y)
		*grid = fdf->grid_y;
	else
		*grid = fdf->grid_x;
}

void	draw_cords(t_fdf *fdf)
{
	int	i;
	int	j;
	int	grid;

	j = -1;
	i = -1;
	draw_cords_helper(fdf, &grid);
	while (++i < fdf->height)
	{
		j = 0;
		set_xy_point(fdf, 0);
		while (++j < fdf->width)
		{
			fdf->color = conv_color2(i, j, fdf);
			fdf->x_to += grid;
			init_points_2d(fdf, 1, grid);
			draw(fdf);
			init_points_2d(fdf, 2, grid);
			draw(fdf);
			set_xy_point(fdf, 1);
		}
		fdf->y_start += grid;
	}
}
