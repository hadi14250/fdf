/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cords2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 05:41:59 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 21:27:45 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	checks for the number of cordinates in 3d 
`array if it's the same or not		*/

void	check_cords(t_fdf *fdf)
{
	int	i[4];

	i[2] = 0;
	check_empty(fdf);
	i[1] = 0;
	i[0] = 0;
	i[3] = 0;
	while (fdf->cords[0][i[3]] != NULL)
		i[3]++;
	while (fdf->cords[++i[0]] != NULL)
	{
		i[1] = 0;
		while (fdf->cords[i[0]][i[1]] != NULL)
		{
			fdf->z[i[0] - 1][i[1]] = ft_atoi(fdf->cords[i[0]][i[1]]);
			i[1]++;
		}
		if (i[3] != i[1])
			i[2]++;
	}
	if (i[2])
		error_and_exit(4, fdf);
}

/*	frees the 3d array	*/

void	free_cords(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (fdf->cords[++i])
		free_split(fdf->cords[i]);
	free(fdf->cords);
}

/*	function used in freeing the 3d array	*/

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
