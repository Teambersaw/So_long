/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:03 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/17 16:06:42 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_parse(int ac, char **av)
{
	char	**map;
	t_elem	elem;

	elem = ft_init_elem();
	map = ft_check_map(ac, av, &elem);
	return (map);
}

int	main(int ac, char **av)
{
	char	**map;
	void	*mlx;
	void	*img;
	void	*mlx_window;
	int		a = 64;
	int		b = 64;

	map = main_parse(ac, av);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "So_long");
	
	img = mlx_xpm_file_to_image(mlx, "sprites/floor.xpm", &a, &b);
	mlx_put_image_to_window(mlx, mlx_window, img, 10, 10);
	mlx_loop(mlx);
	//ft_free(map, NULL);
}
