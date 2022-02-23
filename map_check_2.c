/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:00:50 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/23 13:37:25 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_elem	ft_init_elem(void)
{
	t_elem	elem;

	elem.collect = 0;
	elem.empty = 0;
	elem.exit = 0;
	elem.perso = 0;
	elem.wall = 0;
	return (elem);
}

void	ft_error(char *str, int fd, char *line, char *sfree)
{
	if (sfree)
		free(sfree);
	if (line)
		free(line);
	if (fd)
		close(fd);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_ber(char *ber)
{
	int	i;

	i = lenso(ber) - 4;
	if (!ft_strnstr(ber + i, ".ber", 4))
		ft_error("Map must be a \".ber\"\n", 0, NULL, NULL);
}

int	ft_check_arg(int ac, char **av)
{
	int	fd;
	int	fdd;

	if (ac != 2)
		ft_error("Wrong number of arguments\n", 0, NULL, NULL);
	fdd = open(av[1], __O_DIRECTORY);
	if (fdd > 0)
		ft_error("Argument is a directory\n", fdd, NULL, NULL);
	ft_ber(av[1]);
	fd = open(av[1], O_RDONLY | __O_NOFOLLOW);
	if (fd == -1)
		ft_error("Invalid file\n", 0, NULL, NULL);
	return (fd);
}

char	**ft_initmap(int fd)
{
	char	**map;
	char	*join;
	char	*line;

	join = NULL;
	while (1)
	{
		line = get_next_line(fd, 1);
		if (!line)
			break ;
		join = ft_strjoin_gnl(join, line);
		if (!join)
			ft_error("Malloc failed\n", fd, line, NULL);
		free(line);
	}
	if (!join || join[lenso(join) - 1] != '1' || ft_parse_join(join))
		ft_error("Invalid map\n", fd, line, join);
	map = ft_split(join, '\n');
	if (!map)
		ft_error("Malloc failed\n", fd, line, join);
	free(join);
	free(line);
	return (map);
}
