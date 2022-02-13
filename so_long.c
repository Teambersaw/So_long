/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:03 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/13 23:46:17 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_lenmap(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (s)
// 	{
// 		while (s[i])
// 			i++;
// 	}
// 	return (i);
// }

// void	ft_error(char *str, char *line, int fd, char *after)
// {
// 		if (after)
// 			free(after);
// 		if (fd)
// 			close(fd);
// 		if (line)
// 			free(line);
// 		ft_putstr_fd("Error\n", 2);
// 		ft_putstr_fd(str, 2);
// 		exit(EXIT_FAILURE);
// }

// int	ft_start_line(char *line, int fd)
// {
// 	int	i;
// 	int	len;

// 	i = -1;
// 	len = ft_lenmap(line);
// 	if (len < 6)
// 		ft_error("Invalid map 11\n", line, fd, NULL);
// 	while (++i < len - 1)
// 		if (line[i] != '1')
// 			ft_error("Invalid map 10\n", line, fd, NULL);
// 	if (line[i] != '\n')
// 		ft_error("Invalid map 9\n", line, fd, NULL);
// 	return (len);
// }

//  void	ft_end_line(char *line, int len, int fd)
// {
// 	int	i;

// 	i = -1;
// 	if (ft_lenmap(line) != len - 1)
// 		ft_error("Invalid map 8\n", line, fd, NULL);
// 	while (++i < len - 1)
// 		if (line[i] != '1')
// 			ft_error("Invalid map 7\n", line, fd, NULL);
// 	if (line[i] != '\0')
// 		ft_error("Invalid map 6\n", line, fd, NULL);
// }

// int	ft_element(char *line, int i)
// {
// 	int	element;

// 	element = 0;
// 	if (line[i] == 'E')
// 		element = 10;
// 	if (line[i] == 'P')
// 		element = 3;
// 	return (element);
// }

// int	ft_parse_line(char *line, int len, int fd, char *after)
// {
// 	int		i;
// 	t_elem	element

// 	i = -1;
// 	element = 0;
// 	collectible = 1;
// 	if (ft_lenmap(line) != len)
// 		ft_error("Invalid map 5\n", line, fd, after);
// 	if (line[++i] != '1')
// 			ft_error("Invalid map 4\n", line, fd, after);
// 	while (++i < len - 2)
// 	{
// 		if (line[i] != '1' && line[i] != '0')
// 		{
// 			if (line[i] != 'E' && line[i] != 'P' && line[i] != 'C')
// 				ft_error("Invalid map 3\n", line, fd, after);
// 			element += ft_element(line, i);
// 			if (line[i] == 'C')
// 				collectible = 2;		  
// 		}
// 	}
// 	if (line[i] != '1' || line [i + 1] != '\n')
// 		ft_error("Invalid map 2\n", line, fd, after);
// 	return (element);
// }

// void	ft_valid_map(int fd, int i)
// {
// 	char	*line;
// 	int		len;
// 	int		element;
// 	char	*after;

// 	after = NULL;
// 	element = 0;
// 	line = get_next_line(fd, 1);
// 	if (!line)
// 		ft_error("Invalid map\n", NULL, fd, NULL);
// 	len = ft_start_line(line, fd);
// 	free(line);
// 	line = get_next_line(fd, 1);
// 	if (!line)
// 		ft_error("Invalid map\n", NULL, fd, NULL);
// 	while (++i)
// 	{
// 		after = get_next_line(fd, 1);
// 		if (!after)
// 		{
// 			ft_end_line(line, len, fd);
// 			break;
// 		}
// 		element += ft_parse_line(line, len, fd, after);
// 		free(line);
// 		line = after;
// 	}
// 	if (i >= len - 1 || element != 26)
// 		ft_error("Invalid map 1\n", line, fd, NULL);
// 	free(line);
// }

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

	i = ft_strlen(ber) - 4;
	if(!ft_strnstr(ber + i, ".ber", 4))
		ft_error("Map must be a \".ber\"\n", 0, NULL, NULL);
}

int	ft_check_arg(int ac, char **av)
{
	int fd;

	if (ac != 2)
		ft_error("Wrong number of arguments\n", 0, NULL, NULL);
	ft_ber(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Invalid file\n", 0, NULL, NULL);
	return (fd);
}

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
			break;
		join = ft_strjoin_gnl(join, line);
		if (!join)
			ft_error("Malloc failed\n", fd, line, NULL);
		free(line);
	}
	if (join[ft_strlen(join) - 1] != '1' || ft_parse_join(join))
		ft_error("Invalid map\n", fd, line, join);
	map = ft_split(join, '\n');
	if (!map)
		ft_error("Malloc failed\n", fd, line, join);
	free(join);
	free(line);
	return (map);
}

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

int ft_parse_one(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_valid_map(char **map)
{
	int	i;
	int j;
	int	k;
	int	len;
	t_elem	elem;

	i = 0;
	j = -1;
	elem = ft_init_elem();
	len = ft_strlen(map[i]);
	if (len < 5)
		return (-1);
	while (map[i])
		i++;
	if (i >= len)
		return (-1);
	if (ft_parse_one(map[0]) || ft_parse_one(map[i - 1]))
		return (-1);
	while (++j < i)
	{
		k = 0;
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1' || ft_strlen(map[j]) != len)
			return (-1);
		while (map[j][k])
		{
			if (map[j][k] != '1' && map[j][k] != '0')
			{
				if (map[j][k] == 'P' || map[j][k] == 'C' || map[j][k] == 'E')
				{
					if (map[j][k] == 'P')
						elem.perso += 1;
					if (map[j][k] == 'C')
						elem.collect += 1;
					if (map[j][k] == 'E')
						elem.exit += 1;
				}
				else
					return (-1);
			}
			k++;
		}
	}
	return (0);
}

char	**ft_check_map(int ac, char **av)
{
	int		fd;
	char	**map;

	fd = ft_check_arg(ac, av);
	map = ft_initmap(fd);
	if (!map)
		ft_error("Invalid map\n", fd, NULL, NULL);
	if (ft_valid_map(map) == -1)
	{
		ft_free(map, NULL);
		ft_error("Invalid map 1\n", fd, NULL, NULL);
	}
	return (map);
}

int	main(int ac, char **av)
{
	char	**map;
	t_elem	elem;

	map = ft_check_map(ac, av);
	ft_free(map, NULL);
	return (0);
}
