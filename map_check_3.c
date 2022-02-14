/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:20 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/14 16:27:37 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lenso(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	ft_free(char **tab, char *str)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
	if (str)
		free(str);
}

int	ft_parse_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

t_parse	ft_init_parse(char *map)
{
	t_parse	parse;

	parse.i = 0;
	parse.j = -1;
	parse.k = 0;
	parse.len = lenso(map);
	return (parse);
}
