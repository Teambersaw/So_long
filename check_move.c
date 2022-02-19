/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:59:54 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/19 16:26:48 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_init *init)
{
	if (init->map[init->move.y - 1][init->move.x] == '1')
		return ;
	init->move.y -= 1;
	if (init->map[init->move.y + 1][init->move.x] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit, init->move.x * 64, init->move.i * 64);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor, init->move.x * 64, init->move.i * 64);
	if (init->map[init->move.y][init->move.x] == 'E')
		ft_exit(init);
	if (init->map[init->move.y][init->move.x] == 'C')
		ft_collect(init);
	if (init->map[init->move.y][init->move.x] == '0')
		ft_move(init);
}

void	ft_move_down(t_init *init)
{
	if (init->map[init->move.y + 1][init->move.x] == '1')
		return ;
	init->move.y += 1;
	if (init->map[init->move.y - 1][init->move.x] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit, init->move.x * 64, init->move.i * 64);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor, init->move.x * 64, init->move.i * 64);
	if (init->map[init->move.y][init->move.x] == 'E')
		ft_exit(init);
	if (init->map[init->move.y][init->move.x] == 'C')
		ft_collect(init);
	if (init->map[init->move.y][init->move.x] == '0')
		ft_move(init);
}

void	ft_move_right(t_init *init)
{
	if (init->map[init->move.y][init->move.x + 1] == '1')
		return ;
	init->move.x += 1;
	if (init->map[init->move.y][init->move.x - 1] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit, init->move.j * 64, init->move.y * 64);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor, init->move.j * 64, init->move.y * 64);
	if (init->map[init->move.y][init->move.x] == 'E')
		ft_exit(init);
	if (init->map[init->move.y][init->move.x] == 'C')
		ft_collect(init);
	if (init->map[init->move.y][init->move.x] == '0')
		ft_move(init);
}

void	ft_move_left(t_init *init)
{
	if (init->map[init->move.y][init->move.x - 1] == '1')
		return ;
	init->move.x -= 1;
	if (init->map[init->move.y][init->move.x + 1] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit, init->move.j * 64, init->move.y * 64);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor, init->move.j * 64, init->move.y * 64);
	if (init->map[init->move.y][init->move.x] == 'E')
		ft_exit(init);
	if (init->map[init->move.y][init->move.x] == 'C')
		ft_collect(init);
	if (init->map[init->move.y][init->move.x] == '0')
		ft_move(init);
}

void	ft_quit(t_init *init)
{
	printf("quit\n");
	mlx_destroy_window(init->mlx, init->mlx_win);
}