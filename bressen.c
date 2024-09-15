/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 06:50:52 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:44:15 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawlinex(t_fdf *fdf)
{
	int	index[4];

	index[2] = fdf->x[1] - fdf->x[0];
	index[3] = fdf->y[1] - fdf->y[0];
	index[1] = 1;
	if (index[3] < 0)
	{
		index[1] = -1;
		index[3] *= -1;
	}
	index[0] = (2 * index[3]) - index[2];
	while (fdf->x[0] < fdf->x[1])
	{
		my_mlx_pixel_put(&fdf->img, fdf->x[0], fdf->y[0], fdf->color);
		if (index[0] > 0)
		{
			fdf->y[0] += index[1];
			index[0] += 2 * (index[3] - index[2]);
		}
		else
			index[0] += 2 * index[3];
		fdf->x[0]++;
	}
}

void	ft_drawliney(t_fdf *fdf)
{
	int	index[4];

	index[2] = fdf->x[1] - fdf->x[0];
	index[3] = fdf->y[1] - fdf->y[0];
	index[1] = 1;
	if (index[2] < 0)
	{
		index[1] = -1;
		index[2] *= -1;
	}
	index[0] = (2 * index[2]) - index[3];
	while (fdf->y[0] < fdf->y[1])
	{
		my_mlx_pixel_put(&fdf->img, fdf->x[0], fdf->y[0], fdf->color);
		if (index[0] > 0)
		{
			fdf->x[0] += index[1];
			index[0] += 2 * (index[2] - index[3]);
		}
		else
			index[0] += 2 * index[2];
		fdf->y[0]++;
	}
}

long	absolute(long num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

void	help_for_draw(t_fdf *fdf)
{
	if (fdf->y[0] > fdf->y[1])
	{
		ft_swap(&fdf->x[0], &fdf->x[1]);
		ft_swap(&fdf->y[0], &fdf->y[1]);
		ft_drawliney(fdf);
	}
	else
		ft_drawliney(fdf);
}

void	draw(t_fdf *fdf)
{
	int	dx;
	int	dy;

	if (fdf->color == 0)
		fdf->color = 0xffffff;
	dx = absolute (fdf->x[0] - fdf->x[1]);
	dy = absolute (fdf->y[0] - fdf->y[1]);
	if (dy < dx)
	{
		if (fdf->x[0] > fdf->x[1])
		{
			ft_swap(&fdf->x[0], &fdf->x[1]);
			ft_swap(&fdf->y[0], &fdf->y[1]);
			ft_drawlinex(fdf);
		}
		else
			ft_drawlinex(fdf);
	}
	else
		help_for_draw(fdf);
}
