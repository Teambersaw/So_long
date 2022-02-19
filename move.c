/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:59:10 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/19 01:20:30 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_init *init)
{
	init->sac++;
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.perso, init->move.x * 64, init->move.y * 64);
	init->map[init->move.y][init->move.x] = '0';
	init->move.i = init->move.y;
	init->move.j = init->move.x;
	printf("collect\n");
}

void	ft_exit(t_init *init)
{
	if (init->sac == init->max)
	{
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.perso, init->move.x * 64, init->move.y * 64);
		ft_quit(init->mlx);
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.perso, init->move.x * 64, init->move.y * 64);
	init->move.i = init->move.y;
	init->move.j = init->move.x;
	printf("exit\n");
}

void	ft_move(t_init *init)
{
	printf("zero\n");
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.perso, init->move.x * 64, init->move.y * 64);
	init->move.i = init->move.y;
	init->move.j = init->move.x;

}