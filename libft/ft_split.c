/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 03:59:17 by hakaddou          #+#    #+#             */
/*   Updated: 2022/06/29 05:21:17 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;
	int	done;

	i = 0;
	cnt = 0;
	done = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && !done)
			done = 1;
		else if (s[i] != c && done)
		{
			++cnt;
			done = 0;
		}
		++i;
		ft_printf("%d\r", cnt);
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int			i[2];
	int			ii;
	int			words;
	char		**tmp;

	if (!s)
		return (NULL);
	i[1] = 0;
	words = word_count(s, c);
	tmp = ft_calloc(sizeof(char *), (words + 1));
	if (!tmp)
		return (NULL);
	ii = words;
	words = 0;
	while (s[i[1]] && words < ii)
	{
		i[0] = 0;
		while (s[i[1]] == c)
			i[1]++;
		while (s[i[1] + i[0]] != c && s[i[1] + i[0]] != '\0')
			i[0]++;
		tmp[words++] = ft_substr(s + i[1], 0, i[0]);
		i[1] += i[0];
	}
	tmp[words] = 0;
	return (tmp);
}

// int main ()
// {
// 	char str[] = "hadi is trying printf";
// 	int i = 0;
// 	char **str2 = ft_split (str, ' ');
// 	while (i < word_count (str, ' '))
// 	{
// 		ft_printf ("%s\n", str2[i]);
// 		i++;
// 	}
// 	ft_printf ("Sandy is %d years old\n", 23);
// }