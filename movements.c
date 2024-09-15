/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:24:51 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 21:30:47 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	return_zoom_helper(t_fdf *fdf)
{
	if (fdf->grid > 20 && fdf->grid <= 30)
		return (3);
	else if (fdf->grid > 30 && fdf->grid <= 40)
		return (5);
	else if (fdf->grid > 40 && fdf->grid <= 50)
		return (7);
	else if (fdf->grid > 50 && fdf->grid <= 60)
		return (8);
	else if (fdf->grid > 60 && fdf->grid <= 80)
		return (12);
	else
		return (30);
}

int	return_zoom_grid_ratio(t_fdf *fdf, int key)
{
	if (key == ZOOM_OUT)
		printf("grid is %d\n", fdf->grid);
	if (key == ZOOM_OUT && fdf->grid <= 3)
		return (0);
	if (key == ZOOM_IN)
	{
		fdf->fixed_start_x -= fdf->grid;
		fdf->fixed_start_y -= fdf->grid;
	}
	else
	{
		fdf->fixed_start_x += fdf->grid;
		fdf->fixed_start_y += fdf->grid;
	}
	if (fdf->grid < 10)
		return (1);
	else if (fdf->grid >= 10 && fdf->grid <= 20)
		return (2);
	else
		return (return_zoom_helper(fdf));
}

void	change_z(t_fdf *fdf, int key)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (i < fdf->height)
	{
		d = 0;
		while (d < fdf->width)
		{
			if (key == Z_KEY)
				fdf->z[i][d] += 1;
			else
				fdf->z[i][d] -= 1;
			d++;
		}
		i++;
	}
}

void	fast_shift(int key, t_fdf *fdf)
{
	if (key == S_KEY)
		fdf->fixed_start_y += 70;
	else if (key == W_KEY)
		fdf->fixed_start_y -= 70;
	else if (key == A_KEY)
		fdf->fixed_start_x -= 70;
	else if (key == D_KEY)
		fdf->fixed_start_x += 70;
}

void	shift_cords(int key, t_fdf *fdf)
{
	if (key == DOWN_AROW)
		fdf->fixed_start_y += 10;
	else if (key == UP_AROW)
		fdf->fixed_start_y -= 10;
	else if (key == LEFT_AROW)
		fdf->fixed_start_x -= 10;
	else if (key == RIGHT_AROW)
		fdf->fixed_start_x += 10;
	else if (key == ZOOM_IN)
		fdf->grid += return_zoom_grid_ratio(fdf, key);
	else if (key == ZOOM_OUT)
		fdf->grid -= return_zoom_grid_ratio(fdf, key);
	else if (key == ONE)
		reset_z(fdf);
	else
		fast_shift(key, fdf);
	if (fdf->grid <= 1)
		fdf->grid = 2;
	redo_img(fdf);
	draw_isometric_s(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}
