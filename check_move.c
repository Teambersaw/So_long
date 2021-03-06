/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:59:54 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/24 19:01:13 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_init *init)
{
	if (init->map[init->move.y - 1][init->move.x] == '1')
		return ;
	init->move.y -= 1;
	if (init->sac == init->max && init->map[init->move.y][init->move.x] == 'E')
	{
		mlx_loop_end(init->mlx);
	}
	if (init->map[init->move.y + 1][init->move.x] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit,
			init->move.x * init->var, init->move.i * init->var);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor,
			init->move.x * init->var, init->move.i * init->var);
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
	if (init->sac == init->max && init->map[init->move.y][init->move.x] == 'E')
	{
		mlx_loop_end(init->mlx);
	}
	if (init->map[init->move.y - 1][init->move.x] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit,
			init->move.x * init->var, init->move.i * init->var);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor,
			init->move.x * init->var, init->move.i * init->var);
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
	if (init->sac == init->max && init->map[init->move.y][init->move.x] == 'E')
	{
		mlx_loop_end(init->mlx);
	}
	if (init->map[init->move.y][init->move.x - 1] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit,
			init->move.j * init->var, init->move.y * init->var);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor,
			init->move.j * init->var, init->move.y * init->var);
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
	if (init->sac == init->max && init->map[init->move.y][init->move.x] == 'E')
	{
		mlx_loop_end(init->mlx);
	}
	if (init->map[init->move.y][init->move.x + 1] == 'E')
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.exit,
			init->move.j * init->var, init->move.y * init->var);
	else
		mlx_put_image_to_window(init->mlx, init->mlx_win, init->image.floor,
			init->move.j * init->var, init->move.y * init->var);
	if (init->map[init->move.y][init->move.x] == 'E')
		ft_exit(init);
	if (init->map[init->move.y][init->move.x] == 'C')
		ft_collect(init);
	if (init->map[init->move.y][init->move.x] == '0')
		ft_move(init);
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
