/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:59:54 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/18 19:21:31 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_init *init, t_pos *move)
{
	if (init->map[move->y - 1][move->x] == '1')
	{
		printf("nop\n");
		return ;
	}
	else if (init->map[move->y - 1][move->x] == 'C')
		ft_collect(init, move, 'U');
	else if (init->map[move->y - 1][move->x] == 'E')
		ft_exit(init, move, 'U');
	else
		ft_move(init, move, 'U');
}

void	ft_move_down(t_init *init, t_pos *move)
{
	if (init->map[move->y + 1][move->x] == '1')
	{
		printf("nop\n");
		return ;
	}
	else if (init->map[move->y + 1][move->x] == 'C')
		ft_collect(init, move, 'D');
	else if (init->map[move->y + 1][move->x] == 'E')
		ft_exit(init, move, 'D');
	else
		ft_move(init, move, 'D');
}

void	ft_move_right(t_init *init, t_pos *move)
{
	if (init->map[move->y][move->x + 1] == '1')
	{
		printf("nop\n");
		return ;
	}
	else if (init->map[move->y][move->x + 1] == 'C')
		ft_collect(init, move, 'R');
	else if (init->map[move->y][move->x + 1] == 'E')
		ft_exit(init, move, 'R');
	else
		ft_move(init, move, 'R');
}

void	ft_move_left(t_init *init, t_pos *move)
{
	if (init->map[move->y][move->x - 1] == '1')
	{
		printf("nop\n");
		return ;
	}
	else if (init->map[move->y][move->x - 1] == 'C')
		ft_collect(init, move, 'L');
	else if (init->map[move->y][move->x - 1] == 'E')
		ft_exit(init, move, 'L');
	else
		ft_move(init, move, 'L');
}

void	ft_quit(t_init *init, t_pos *move)
{
	printf("quit\n");
	mlx_destroy_window(init->mlx, init->mlx_win);
}