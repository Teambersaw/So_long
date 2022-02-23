/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:59:10 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/23 15:55:28 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free_image(t_image *image)
{
	
}

void	ft_hola(char **map, void *mlx, int i)
{
	if (mlx)
		mlx_destroy_display(mlx);
	ft_free(map, mlx);
	if (i == 0)
		ft_putstr_fd("Error occurred: init the mlx\n", 2);
	else if (i == 1)
		ft_putstr_fd("Your map is too big ! This is not a Ubisoft game !\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error occurred: create mlx window\n", 2);
	exit(1);
}

int	ft_size(void *mlx, char **map)
{
	int	x;
	int	y;
	int	var;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	var = 128;
	while (map[i])
		i++;
	mlx_get_screen_size(mlx, &x, &y);
	while (var >= 16)
	{
		if (x >= lenso(map[0]) * var && y >= i * var)
			return (var);
		else
			var = var / 2;
	}
	return (0);
}

void	ft_collect(t_init *init)
{
	init->sac++;
	init->map[init->move.y][init->move.x] = '0';
	init->move.i = init->move.y;
	init->move.j = init->move.x;
}

void	ft_exit(t_init *init)
{
	init->count++;
	ft_putnbr_fd(init->count, 1);
	write(1, "\n", 1);
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exiton,
		init->move.x * init->var, init->move.y * init->var);
	init->move.i = init->move.y;
	init->move.j = init->move.x;
}

void	ft_move(t_init *init)
{
	init->count++;
	ft_putnbr_fd(init->count, 1);
	write(1, "\n", 1);
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.perso,
		init->move.x * init->var, init->move.y * init->var);
	init->move.i = init->move.y;
	init->move.j = init->move.x;
}
