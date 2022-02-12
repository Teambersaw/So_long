/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:03 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/12 16:35:39 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, int fd)
{
		if (fd)
			close(fd);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
		exit(EXIT_FAILURE);
}

void	ft_valid_map(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("Invalid FD\n", 0);
	line = get_next_line(fd, 1);
	if (!line)
		ft_error("Invalid map\n", fd);
	ft_parse_line(line);
	while (++i > -1)
	{
		line = get_next_line(fd, 1);
		if (!line)
			break;
		
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	ft_valid_map(av[1]);
	return (0);
}
