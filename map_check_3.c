/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:20 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/24 19:49:59 by teambersaw       ###   ########.fr       */
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
			if (tab[i])
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

char	**ft_name_image(int var)
{
	char	**name;

	name = malloc(sizeof(char *) * 7);
	if (!name)
		return (NULL);
	name[0] = ft_strjoin_gnl(ft_itoa(var), "sprites/floor.xpm");
	name[1] = ft_strjoin_gnl(ft_itoa(var), "sprites/wall.xpm");
	name[2] = ft_strjoin_gnl(ft_itoa(var), "sprites/objet.xpm");
	name[3] = ft_strjoin_gnl(ft_itoa(var), "sprites/exit.xpm");
	name[4] = ft_strjoin_gnl(ft_itoa(var), "sprites/perso.xpm");
	name[5] = ft_strjoin_gnl(ft_itoa(var), "sprites/exiton.xpm");
	name[6] = NULL;
	return (name);
}
