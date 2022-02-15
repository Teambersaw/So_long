# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 14:42:37 by teambersaw        #+#    #+#              #
#    Updated: 2022/02/15 15:34:29 by jrossett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

CFLAGS= -Wall -Wextra -Werror

SRCS= so_long.c map_check_1.c map_check_2.c map_check_3.c \

OBJS= ${SRCS:.c=.o}

NAME= so_long

${NAME}: ${OBJS} so_long.h
	${MAKE} -s all -C libft
	${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	${MAKE} -s clean -C libft

fclean: clean
	rm -f ${NAME}
	${MAKE} -s fclean -C libft

re: fclean all

.PHONY: all clean fclean re