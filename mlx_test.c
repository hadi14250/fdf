/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:22:30 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:51:43 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x >= WINDOW_SIZE || y >= WIND_BORDER || x <= 0 || y <= 0)
		return ;
	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *) dst = color;
}

void	init_win_img_pixil(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, 1400, 1400, fdf->file);
	fdf->img.img = mlx_new_image(fdf->mlx, 1400, 1400);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	draw_isometric(fdf);
}

int	exit_app(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	free_cords(fdf);
	free_map(fdf);
	exit(0);
	return (0);
}

void	destroy_win_imf_free(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	free_cords(fdf);
	free_map(fdf);
	exit(0);
}

void	redo_img(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, 1400, 1400);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
}
