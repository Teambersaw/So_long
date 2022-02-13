/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:03 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/13 18:25:28 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lenmap(const char *s)
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

void	ft_error(char *str, char *line, int fd, char *after)
{
		if (after)
			free(after);
		if (fd)
			close(fd);
		if (line)
			free(line);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
		exit(EXIT_FAILURE);
}

int	ft_start_line(char *line, int fd)
{
	int	i;
	int	len;

	i = -1;
	len = ft_lenmap(line);
	if (len < 6)
		ft_error("Invalid map 11\n", line, fd, NULL);
	while (++i < len - 1)
		if (line[i] != '1')
			ft_error("Invalid map 10\n", line, fd, NULL);
	if (line[i] != '\n')
		ft_error("Invalid map 9\n", line, fd, NULL);
	return (len);
}

 void	ft_end_line(char *line, int len, int fd)
{
	int	i;

	i = -1;
	if (ft_lenmap(line) != len - 1)
		ft_error("Invalid map 8\n", line, fd, NULL);
	while (++i < len - 1)
		if (line[i] != '1')
			ft_error("Invalid map 7\n", line, fd, NULL);
	if (line[i] != '\0')
		ft_error("Invalid map 6\n", line, fd, NULL);
}

int	ft_element(char *line, int i)
{
	int	element;

	element = 0;
	if (line[i] == 'E')
		element = 10;
	if (line[i] == 'P')
		element = 3;
	return (element);
}

int	ft_parse_line(char *line, int len, int fd, char *after)
{
	int		i;
	int		element;
	int		collectible;

	i = -1;
	element = 0;
	collectible = 1;
	if (ft_lenmap(line) != len)
		ft_error("Invalid map 5\n", line, fd, after);
	if (line[++i] != '1')
			ft_error("Invalid map 4\n", line, fd, after);
	while (++i < len - 2)
	{
		if (line[i] != '1' && line[i] != '0')
		{
			if (line[i] != 'E' && line[i] != 'P' && line[i] != 'C')
				ft_error("Invalid map 3\n", line, fd, after);
			element += ft_element(line, i);
			if (line[i] == 'C')
				collectible = 2;		  
		}
	}
	if (line[i] != '1' || line [i + 1] != '\n')
		ft_error("Invalid map 2\n", line, fd, after);
	return (element * collectible);
}

void	ft_valid_map(int fd, int i)
{
	char	*line;
	int		len;
	int		element;
	char	*after;

	after = NULL;
	element = 0;
	line = get_next_line(fd, 1);
	if (!line)
		ft_error("Invalid map\n", NULL, fd, NULL);
	len = ft_start_line(line, fd);
	free(line);
	line = get_next_line(fd, 1);
	if (!line)
		ft_error("Invalid map\n", NULL, fd, NULL);
	while (++i)
	{
		after = get_next_line(fd, 1);
		if (!after)
		{
			ft_end_line(line, len, fd);
			break;
		}
		element += ft_parse_line(line, len, fd, after);
		free(line);
		line = after;
	}
	if (i >= len - 1 || element != 26)
		ft_error("Invalid map 1\n", line, fd, NULL);
	free(line);
}

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	i = 1;
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Invalid FD\n", NULL, 0, NULL);
	ft_valid_map(fd, i);
	close(fd);
	return (0);
}
