# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:39:27 by fluchten          #+#    #+#              #
#    Updated: 2023/01/19 12:26:54 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC_DIR = -I includes

SRCS_DIR = srcs
SRCS =	args/args.c \
		operations/push.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap.c \
		sort/sort.c \
		sort/sort_little.c \
		stack/stack_check.c \
		stack/stack_init.c \
		stack/stack_utils.c \
		utils/utils.c \
		main.c

OBJS = $(addprefix ${SRCS_DIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INC_DIR} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re