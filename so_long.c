/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:03 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/14 16:24:51 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	t_elem	elem;

	elem = ft_init_elem();
	map = ft_check_map(ac, av, &elem);
	ft_free(map, NULL);
	return (0);
}
