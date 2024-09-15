/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:26:40 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 21:05:40 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keys_handler(int key, t_fdf *fdf)
{
	ft_printf("button: %d\n", key);
	if (key == ESC)
		destroy_win_imf_free(fdf);
	if (key == LEFT_AROW || key == RIGHT_AROW
		|| key == UP_AROW || key == DOWN_AROW || key == ONE)
		shift_cords(key, fdf);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		shift_cords(key, fdf);
	if (key == W_KEY || key == S_KEY || key == D_KEY || key == A_KEY)
		shift_cords(key, fdf);
	if (key == TWO)
		draw_2d_plane(fdf);
	if (key == THREE)
		redraw_3d(fdf);
	if (key == MESH || key == NMESH)
		mesh_them(fdf, key);
	return (0);
}

void	put_img_free(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
	mlx_hook(fdf->mlx_win, 17, 0, exit_app, fdf);
	mlx_hook(fdf->mlx_win, 2, 0, keys_handler, fdf);
	mlx_loop(fdf->mlx);
}
