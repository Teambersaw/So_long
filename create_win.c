/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:03:21 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/18 17:30:34 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(void *mlx, void *mlx_window, char **map, t_image image)
{
	t_pos	pos;

	pos = ft_init_pos();
	while(map[pos.i])
	{
		pos.j = 0;
		while(map[pos.i][pos.j])
		{
			if (map[pos.i][pos.j] == '1')
				mlx_put_image_to_window(mlx, mlx_window, image.wall, pos.x, pos.y);
			if (map[pos.i][pos.j] == '0')
				mlx_put_image_to_window(mlx, mlx_window, image.floor, pos.x, pos.y);
			if (map[pos.i][pos.j] == 'E')
				mlx_put_image_to_window(mlx, mlx_window, image.exit, pos.x, pos.y);
			if (map[pos.i][pos.j] == 'P')
				mlx_put_image_to_window(mlx, mlx_window, image.perso, pos.x, pos.y);
			if (map[pos.i][pos.j] == 'C')
				mlx_put_image_to_window(mlx, mlx_window, image.objet, pos.x, pos.y);
			pos.j++;
			pos.x += 64;
		}
		pos.x = 0;
		pos.i++;
		pos.y += 64;
	}
}

void	*ft_init_window(char **map, void *mlx)
{
	int	x;
	int	y;
	void	*mlx_window;

	y = 0;
	x = lenso(map[0]);
	while (map[y])
		y++;
	mlx_window = mlx_new_window(mlx, x * 64, y * 64, "So_long");
	return (mlx_window);
}

t_image	ft_init_image(void *mlx)
{
	t_image	image;
	int		x;
	int		y;

	x = 64;
	y = 64;
	image.floor = mlx_xpm_file_to_image(mlx, "sprites/floor.xpm", &x, &y);
	image.wall = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &x, &y);
	image.objet = mlx_xpm_file_to_image(mlx, "sprites/objet.xpm", &x, &y);
	image.exit = mlx_xpm_file_to_image(mlx, "sprites/exit.xpm", &x, &y);
	image.perso = mlx_xpm_file_to_image(mlx, "sprites/perso.xpm", &x, &y);
	return (image);
}

t_pos	ft_init_pos(void)
{
	t_pos	pos;

	pos.i = 0;
	pos.j = 0;
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

char	**main_parse(int ac, char **av)
{
	char	**map;
	t_elem	elem;

	elem = ft_init_elem();
	map = ft_check_map(ac, av, &elem);
	return (map);
}