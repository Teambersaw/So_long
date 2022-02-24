/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:59:10 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/24 19:00:03 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_image(t_image *image, void *mlx, char **map, void *mlx_win)
{
	if (image->exit)
		mlx_destroy_image(mlx, image->exit);
	if (image->exiton)
		mlx_destroy_image(mlx, image->exiton);
	if (image->perso)
		mlx_destroy_image(mlx, image->perso);
	if (image->objet)
		mlx_destroy_image(mlx, image->objet);
	if (image->wall)
		mlx_destroy_image(mlx, image->wall);
	if (image->floor)
		mlx_destroy_image(mlx, image->floor);
	ft_hola(map, mlx, 3, mlx_win);
}

void	ft_hola(char **map, void *mlx, int i, void *mlx_win)
{
	if (mlx_win)
		mlx_destroy_window(mlx, mlx_win);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	ft_free(map, NULL);
	if (i == 0)
		ft_putstr_fd("Error occurred: init the mlx\n", 2);
	else if (i == 1)
		ft_putstr_fd("Your map is too big ! This is not a Ubisoft game !\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error occurred: window creation\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error occurred: image creation\n", 2);
	exit(1);
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
