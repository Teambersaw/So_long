/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:00 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/21 22:01:05 by teambersaw       ###   ########.fr       */
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
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

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

typedef struct s_image
{
	void	*floor;
	void	*wall;
	void	*objet;
	void	*perso;
	void	*exit;
	void	*exiton;	
} 			t_image;

typedef struct s_pos
{
	int	i;
	int	j;
	int	x;
	int	y;
}	t_pos;

typedef struct s_init
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_image	image;
	t_pos	move;
	int		sac;
	int		max;
	int		var;
	int		count;
}	t_init;

t_elem	ft_init_elem(void);
t_parse	ft_init_parse(char *map);
t_pos	ft_init_pos(void);
t_image	ft_init_image(void *mlx, int var);
t_init	ft_init_struct(int ac, char **av);
t_pos	ft_get_pos(char **map);
char	**ft_initmap(int fd);
int		lenso(const char *s);
int		ft_parse_join(char *join);
int		ft_parse_one(char *str);
int		ft_check_arg(int ac, char **av);
int		ft_valid_map(char **map, t_elem *elem);
char	**ft_check_map(int ac, char **av, t_elem *elem);
void	ft_free(char **tab, char *str);
void	ft_error(char *str, int fd, char *line, char *sfree);
void	ft_put_image(void *mlx, void *mlx_window, t_init *init, t_image image);
void	ft_objet(char **map, t_elem *elem, t_parse parse);
void	*ft_init_window(char **map, void *mlx, int var);
int		ft_little_verif(t_parse *parse, char **map);
void	ft_ber(char *ber);
char	**main_parse(int ac, char **av);
void	ft_move_up(t_init *init);
void	ft_move_down(t_init *init);
void	ft_move_left(t_init *init);
void	ft_move_right(t_init *init);
void	ft_collect(t_init *init);
void	ft_exit(t_init *init);
void	ft_move(t_init *init);
void	ft_quit(t_init *init);

#endif