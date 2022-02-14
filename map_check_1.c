/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:57:12 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/14 16:24:30 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse_join(char *join)
{
	int	i;

	i = 0;
	if (join[i] == '\n')
		return (1);
	while (join[i])
	{
		if (join[i] == '\n' && join[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_little_verif(t_parse *parse, char **map)
{
	if (parse->len < 5)
		return (-1);
	while (map[parse->i])
		parse->i++;
	if (parse->i >= parse->len)
		return (-1);
	if (ft_parse_one(map[0]) || ft_parse_one(map[parse->i - 1]))
		return (-1);
	return (0);
}

void	ft_objet(char **map, t_elem *elem, t_parse parse)
{
	if (map[parse.j][parse.k] == 'P')
		elem->perso += 1;
	if (map[parse.j][parse.k] == 'C')
		elem->collect += 1;
	if (map[parse.j][parse.k] == 'E')
		elem->exit += 1;
}

int	ft_valid_map(char **map, t_elem *elem)
{
	t_parse	p;

	p = ft_init_parse(map[0]);
	if (ft_little_verif(&p, map) == -1)
		return (-1);
	while (++p.j < p.i)
	{
		p.k = 0;
		if (map[p.j][0] != '1' || map[p.j][lenso(map[p.j]) - 1] != '1'
			|| lenso(map[p.j]) != p.len)
			return (-1);
		while (map[p.j][p.k])
		{
			if (map[p.j][p.k] != '1' && map[p.j][p.k] != '0')
			{
				if (map[p.j][p.k] == 'P' || map[p.j][p.k] == 'C'
					|| map[p.j][p.k] == 'E')
					ft_objet(map, elem, p);
				else
					return (-1);
			}
			p.k++;
		}
	}
	return (0);
}

char	**ft_check_map(int ac, char **av, t_elem *elem)
{
	int		fd;
	char	**map;

	fd = ft_check_arg(ac, av);
	map = ft_initmap(fd);
	if (!map)
		ft_error("Invalid map\n", fd, NULL, NULL);
	if (ft_valid_map(map, elem) == -1)
	{
		ft_free(map, NULL);
		ft_error("Invalid map\n", fd, NULL, NULL);
	}
	if (elem->perso != 1 || elem->exit != 1 || elem->collect < 1)
	{
		ft_free(map, NULL);
		ft_error("Invalid map\n", fd, NULL, NULL);
	}
	return (map);
}
