/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:03 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/23 13:19:57 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_collect(char **map)
{
	int	i;
	int	j;
	int	collectible;

	collectible = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	return (collectible);
}

t_pos	ft_get_pos(char **map)
{
	t_pos	move;

	move = ft_init_pos();
	while (map[move.i])
	{
		move.j = 0;
		while (map[move.i][move.j])
		{
			if (map[move.i][move.j] == 'P')
			{
				move.x = move.j;
				move.y = move.i;
			}
			move.j++;
		}
		move.i++;
	}
	move.j = move.x;
	move.i = move.y;
	return (move);
}

int	key_hook(int key_code, t_init *init)
{
	if (key_code == 65307)
		ft_quit(init);
	if (key_code == 'w' || key_code == 65362)
		ft_move_up(init);
	if (key_code == 's' || key_code == 65364)
		ft_move_down(init);
	if (key_code == 'a' || key_code == 65361)
		ft_move_left(init);
	if (key_code == 'd' || key_code == 65363)
		ft_move_right(init);
	return (0);
}

t_init	ft_init_struct(int ac, char **av)
{
	t_init	init;

	init.map = main_parse(ac, av);
	init.mlx = mlx_init();
	if (!init.mlx)
	{
		ft_free(init.map, NULL);
		exit(1);
	}
	init.var = 64;
	init.mlx_win = ft_init_window(init.map, init.mlx, init.var);
	init.image = ft_init_image(init.mlx, init.var);
	init.move = ft_get_pos(init.map);
	init.sac = 0;
	init.max = ft_count_collect(init.map);
	init.count = 0;
	return (init);
}

int	main(int ac, char **av)
{
	t_init	init;

	init = ft_init_struct(ac, av);
	ft_put_image(init.mlx, init.mlx_win, &init, init.image);
	init.map[init.move.y][init.move.x] = '0';
	write(1, "0\n", 2);
	mlx_hook(init.mlx_win, 2, (1L << 0), key_hook, &init);
	mlx_hook(init.mlx_win, 17, (1L << 0), mlx_loop_end, init.mlx);
	mlx_loop(init.mlx);
	mlx_destroy_image(init.mlx, init.image.exit);
	mlx_destroy_image(init.mlx, init.image.perso);
	mlx_destroy_image(init.mlx, init.image.wall);
	mlx_destroy_image(init.mlx, init.image.floor);
	mlx_destroy_image(init.mlx, init.image.exiton);
	mlx_destroy_image(init.mlx, init.image.objet);
	mlx_destroy_window(init.mlx, init.mlx_win);
	mlx_destroy_display(init.mlx);
	free(init.mlx);
	ft_free(init.map, NULL);
	return (0);
}
