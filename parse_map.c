/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:59:38 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 22:53:29 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	just calls the functions that checks the file and it's exdntsion,
opening the file, and parsing the map.	*/
void	init_check_open_parse(int ac, char **av, t_fdf *fdf)
{
	check_validity(ac, av);
	ft_open_and_parse(fdf, av[1]);
	parse_cords(fdf);
	check_cords(fdf);
	print_cords(fdf);
	fdf->grid_x = WIND_BORDER / fdf->width;
	fdf->grid_y = WIND_BORDER / fdf->height;
	fdf->grid = return_smaller_grid(fdf);
	fdf->x_start = XSTART;
	fdf->y_start = YSTART;
	fdf->y_to = fdf->y_start;
	fdf->x_to = fdf->x_start;
	fdf->zoom_tracker = 0;
	fdf->fixed_grid = return_smaller_grid(fdf);
	fdf->fixed_start_x = 600;
	fdf->fixed_start_y = 300;
}
/*	counts lines in a file and closes it	*/

void	count_lines(t_fdf *fdf)
{
	char	*str;

	fdf->line_count = 0;
	str = ft_calloc(1, 1);
	*str = 'H';
	while (str)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		str = get_next_line(fdf->fd);
		if (str)
			fdf->line_count++;
	}
	ft_printf("line count: %d\n", fdf->line_count);
	if (fdf->line_count <= 1)
		error_and_exit(2, fdf);
	close(fdf->fd);
}

/*	parses the content of a file to a 2d array line by line	*/
void	parse_map(t_fdf *fdf)
{
	int		i;

	count_lines(fdf);
	fdf->map = ft_calloc(fdf->line_count + 1, sizeof(char **));
	fdf->map[fdf->line_count] = NULL;
	i = 0;
	fdf->fd = open(fdf->file, O_RDONLY);
	if (fdf->fd == -1)
		error_and_exit(3, fdf);
	while (1)
	{
		fdf->map[i] = get_next_line(fdf->fd);
		if (fdf->map[i] == NULL)
			break ;
		i++;
	}
}

/*	checks if all the lines in a file have the same length	*/
void	check_map_length(t_fdf *fdf)
{
	int	i;
	int	len;

	i = 0;
	len = word_count(fdf->map[i], ' ');
	while (fdf->map[i] != NULL && i < fdf->line_count)
	{
		ft_printf("Line %d is %d long\n", i + 1, len);
		if (len != word_count(fdf->map[i], ' '))
			error_and_exit(4, fdf);
		i++;
	}
}

/*	opens the .fdf file for reading and calls others functions	*/
void	ft_open_and_parse(t_fdf *fdf, char *file)
{
	fdf->file = file;
	fdf->fd = open(fdf->file, O_RDONLY);
	if (fdf->fd == -1)
		error_and_exit(1, fdf);
	parse_map(fdf);
	close(fdf->fd);
}
