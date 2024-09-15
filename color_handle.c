/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:51:40 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:59:53 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	helper_for_convert_color(char *str, int *index[0], int  index[2],)

long	convert_color(char *str)
{
	int	index[3];

	index[0] = 0;
	index[1] = 1;
	index[2] = ft_strlen(str);
	while (--index[2] >= 0)
	{
		if (str[index[2]] >= '0' && str[index[2]] <= '9')
		{
			index[0] += (str[index[2]] - 48) * index[1];
			index[1] *= 16;
		}
		else if (str[index[2]] >= 'A' && str[index[2]] <= 'F')
		{
			index[0] += (str[index[2]] - 55) * index[1];
			index[1] *= 16;
		}
		else if (str[index[2]] >= 'a' && str[index[2]] <= 'f')
		{
			index[0] += (str[index[2]] - 87) * index[1];
			index[1] *= 16;
		}
	}
	return (index[0]);
}

long	conv_color2(int i, int j, t_fdf *fdf)
{
	return (convert_color(ft_strnstr(fdf->cords[i][j], "0x", 11)));
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	reset_z(t_fdf *fdf)
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
			ft_swap(&fdf->z[i][d], &fdf->z_b[i][d]);
			d++;
		}
		i++;
	}
}
