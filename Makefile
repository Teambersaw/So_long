# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 14:42:37 by teambersaw        #+#    #+#              #
#    Updated: 2022/02/15 22:35:39 by teambersaw       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

CFLAGS= -Wall -Wextra -Werror

SRCS= so_long.c map_check_1.c map_check_2.c map_check_3.c \

OBJS= ${SRCS:.c=.o}

HEADER= so_long.h

NAME= so_long

${NAME}: ${OBJS} ${HEADER}
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