/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:00 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/13 18:45:04 by teambersaw       ###   ########.fr       */
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

struct s_list
{
	/* data */
} t_list;

int		ft_start_line(char *line, int fd);
void	ft_end_line(char *last, int len, int fd);
void	ft_error(char *str, char *line, int fd, char *after);
int		ft_parse_line(char *line, int len, int fd, char *after);
void	ft_valid_map(int fd, int i);

#endif