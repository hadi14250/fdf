/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:59:32 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 05:48:58 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	counts the bytes (chars) in the 2d array fdf->map	*/
int	count_bytes(t_fdf *fdf)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (fdf->map[i])
	{
		d += ft_strlen(fdf->map[i]);
		i++;
	}
	return (d);
}

/*	reads fdf->map and splits them using spaces
	and stores them in  a 3d array	*/

void	parse_cords(t_fdf *fdf)
{
	int		i;

	fdf->cords = ft_calloc(fdf->line_count + 1,
			count_bytes(fdf) + sizeof(char *));
	i = 0;
	while (i < fdf->line_count)
	{
		ft_printf("	Cords parsed of line %d of %d\r", i, fdf->line_count);
		fdf->cords[i] = ft_split(fdf->map[i], ' ');
		i++;
	}
	fdf->cords[i] = NULL;
	ft_printf("\n");
	fdf->width = word_count(fdf->map[0], ' ');
}

void	check_empty(t_fdf *fdf)
{
	int		i;
	size_t	d;

	d = 0;
	i = 0;
	while (fdf->cords[0][0][i] != '\0')
	{
		if (fdf->cords[0][0][i] == '\n')
			d++;
		i++;
	}
	if (d == ft_strlen(fdf->cords[0][0]))
		error_and_exit(4, fdf);
}

void	print_cords(t_fdf *fdf)
{
	int	i;
	int	d;

	d = 0;
	i = 0;
	while (fdf->cords[i] != NULL)
	{
		d = 0;
		while (fdf->cords[i][d] != NULL)
			d++;
		i++;
	}
	fdf->height = i;
}
