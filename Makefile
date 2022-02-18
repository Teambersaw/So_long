# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 14:42:37 by teambersaw        #+#    #+#              #
#    Updated: 2022/02/18 16:30:37 by teambersaw       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

#CFLAGS= -Wall -Wextra -Werror

SRCS= so_long.c map_check_1.c map_check_2.c map_check_3.c move.c check_move.c create_win.c \

OBJS= ${SRCS:.c=.o}

HEADER= so_long.h

NAME= so_long

${NAME}: ${OBJS} ${HEADER}
	${MAKE} -s all -C libft
	${MAKE} -s all -C minilibx-linux
	${CC} ${OBJS} libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	${MAKE} -s clean -C libft

fclean: clean
	rm -f ${NAME}
	${MAKE} -s fclean -C libft

re: fclean all

.PHONY: all clean fclean re