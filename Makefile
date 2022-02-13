# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 14:42:37 by teambersaw        #+#    #+#              #
#    Updated: 2022/02/13 20:18:15 by teambersaw       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

#CFLAGS= -Wall -Wextra -Werror

SRCS= so_long.c \

OBJS= ${SRCS:.c=.o}

NAME= so_long

${NAME}: ${OBJS}
	${MAKE} -s all -C libft
	${CC} ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	${MAKE} -s clean -C libft

fclean: clean
	rm -f ${NAME}
	${MAKE} -s fclean -C libft

re: fclean all

.PHONY: all clean fclean re