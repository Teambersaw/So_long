/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:00 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/15 21:27:29 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_elem
{
	int	collect;
	int	exit;
	int	perso;
	int	empty;
	int	wall;
}	t_elem;

typedef struct s_parse
{
	int	i;
	int	j;
	int	k;
	int	len;
}	t_parse;

t_elem	ft_init_elem(void);
t_parse	ft_init_parse(char *map);
char	**ft_initmap(int fd);
int		lenso(const char *s);
int		ft_parse_join(char *join);
int		ft_parse_one(char *str);
int		ft_check_arg(int ac, char **av);
int		ft_valid_map(char **map, t_elem *elem);
char	**ft_check_map(int ac, char **av, t_elem *elem);
void	ft_free(char **tab, char *str);
void	ft_error(char *str, int fd, char *line, char *sfree);
void	ft_objet(char **map, t_elem *elem, t_parse parse);
int		ft_little_verif(t_parse *parse, char **map);
void	ft_ber(char *ber);
int		main(int ac, char **av);

#endif