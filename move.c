/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:59:10 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/18 19:25:20 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_image(t_init *init)
{
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor, init->move.x * 64, init->move.y * 64);
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.perso, (init->move.x + 1) * 64, (init->move.y -1) * 64);
}

void	ft_collect(t_init *init, t_pos *move, char c)
{
	init->sac++;
	//mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit, init->move.x * 64, init->move.y * 64);
	//mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.perso, (init->move.x + 1) * 64, (init->move.y -1) * 64);
	printf("collect\n");
}

void	ft_exit(t_init *init, t_pos *move, char c)
{
	// if (init->sac == init->max)
	// {
	// 	//deplacement + exit
	// }
	// else
	// 	//deplacement
	printf("exit\n");
}

void	ft_move(t_init *init, t_pos *move, char c)
{
	printf("move\n");
	init->move.x = move->x;
	init->move.y = move->y;
	printf("nb move %d\n", init->move.x);
	mlx_loop_hook(init->mlx, next_image ,init);
}