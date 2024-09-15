/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:35:04 by hakaddou          #+#    #+#             */
/*   Updated: 2022/07/27 05:33:12 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	prints error and exits depending on the flag passed	*/
void	error_and_exit(int flag, t_fdf *fdf)
{
	if (flag == 0)
		ft_printf("\033[31mError:\033[0m invalid map\n");
	else if (flag == 1)
		ft_printf("\033[31mError:\033[0m failed to open file.\n");
	else if (flag == 2)
	{
		ft_printf("\033[31mError:\033[0m no data found\n");
		close(fdf->fd);
	}
	else if (flag == 3)
		ft_printf("\033[31mError:\033[0m error in parse_map function\n");
	else if (flag == 4)
	{
		ft_printf("\033[31mError:\033[0m invalid map line length\n");
		free_cords(fdf);
		free_map(fdf);
		close(fdf->fd);
	}
	exit(1);
}

/*	checks if file ends with -> .fdf	*/
void	check_dot_fdf(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'f' && str[i - 1] == 'd'
		&& str[i - 2] == 'f' && str[i - 3] == '.')
	{
		if (i + 1 == 4)
			error_and_exit(0, NULL);
		else
			return ;
	}
	else
		error_and_exit(0, NULL);
}

/*	checks if there are more than 2 dots	*/
void	check_validity(int ac, char **av)
{
	int		i;
	int		d;

	if (ac != 2)
		error_and_exit(0, NULL);
	i = 0;
	d = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] == '.')
			d++;
		i++;
	}
	if (d != 1)
		error_and_exit(0, NULL);
	check_dot_fdf(av[1]);
}

/*	frees the double pointer that is storing the file lines	*/
void	free_map(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (fdf->map[++i] != NULL)
		free(fdf->map[i]);
	free(fdf->map);
}

/*	prints the file content line by line	*/
void	print_map(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (fdf->map[++i] != NULL)
		ft_printf("%s", fdf->map[i]);
}
