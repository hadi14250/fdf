/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_points3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:47:35 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:54:05 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_set_points_helper(t_fdf *fdf, int *grid, int flag)
{
	if (flag == 3)
	{
		fdf->grid = return_smaller_grid(fdf);
		if (fdf->width * fdf->height > 100000)
			*grid = fdf->grid * 2;
		else
			*grid = fdf->grid;
		fdf->grid = *grid;
	}
}

void	iso_set_points(t_fdf *fdf, int *grid, int flag, int i)
{
	if (flag == 0)
	{
		fdf->x_start = XSTART - i * *grid * 0.8;
		fdf->x_to = fdf->x_start;
		fdf->y_start = YSTART + i * *grid * 0.4;
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
	else
		iso_set_points_helper(fdf, grid, flag);
}

int	z_conv(int z, int grid)
{
	if (z < 4)
		return (z);
	else
		return (z / 3);
	grid++;
}
