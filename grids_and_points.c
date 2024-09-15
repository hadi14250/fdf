/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grids_and_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:22:06 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:47:24 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points_1(t_fdf *fdf, int i, int j, int grid)
{
	fdf->x[0] = fdf->x_start;
	fdf->y[0] = fdf->y_start - (z_conv(fdf->z[i][j],
				fdf->grid)) * grid * 0.9;
	fdf->x[1] = fdf->x_to;
	fdf->y[1] = fdf->y_to - ((z_conv(fdf->z[i][j + 1],
					fdf->grid)) * grid * 0.9);
}

void	init_points_2(t_fdf *fdf, int i, int j, int grid)
{
	fdf->x[0] = fdf->x_start;
	fdf->y[0] = fdf->y_start - (z_conv(fdf->z[i][j],
				fdf->grid)) * grid * 0.9;
	fdf->x[1] = fdf->x_to - grid * 1.6;
	fdf->y[1] = fdf->y_to - (z_conv(fdf->z[i + 1][j],
				fdf->grid)) * grid * 0.9;
}

void	draw_isometric(t_fdf *fdf)
{
	int	i;
	int	j;
	int	grid;

	j = -1;
	i = -1;
	iso_set_points(fdf, &grid, 3, i);
	while (++i + 1 < fdf->height)
	{
		j = 0;
		iso_set_points(fdf, &grid, 0, i);
		while (++j + 1 < fdf->width)
		{
			fdf->color = conv_color2(i, j, fdf);
			iso_set_points(fdf, &grid, 1, i);
			init_points_1(fdf, i, j, grid);
			draw (fdf);
			init_points_2(fdf, i, j, grid);
			draw (fdf);
			iso_set_points(fdf, &grid, 2, i);
		}
	}
}

void	iso_s_set_points(t_fdf *fdf, int *grid, int flag, int i)
{
	if (flag == 0)
	{
		fdf->x_start = (fdf->fixed_start_x - i * *grid * 0.8);
		fdf->x_to = fdf->x_start;
		fdf->y_start = fdf->fixed_start_y + i * *grid * 0.4;
		fdf->y_to = fdf->y_start;
	}
	else if (flag == 1)
	{
		fdf->x_to += *grid * 0.8;
		fdf->y_to += *grid * 0.4;
	}
	else if (flag == 2)
	{
		fdf->x_start = fdf->x_to;
		fdf->y_start = fdf->y_to;
	}
}

void	draw_isometric_s(t_fdf *fdf)
{
	int	i;
	int	j;
	int	grid;

	j = -1;
	i = -1;
	grid = fdf->grid;
	while (++i + 1 < fdf->height)
	{
		j = 0;
		iso_s_set_points(fdf, &grid, 0, i);
		while (++j + 1 < fdf->width)
		{
			fdf->color = conv_color2(i, j, fdf);
			iso_set_points(fdf, &grid, 1, i);
			init_points_1(fdf, i, j, grid);
			draw (fdf);
			init_points_2(fdf, i, j, grid);
			draw (fdf);
			iso_set_points(fdf, &grid, 2, i);
		}
	}
}
