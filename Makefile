# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:39:27 by fluchten          #+#    #+#              #
#    Updated: 2023/01/25 19:43:42 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS_DIR = srcs
SRCS =	args/args.c \
		operations/push.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap.c \
		sort/sort_big.c \
		sort/sort_little.c \
		sort/sort.c \
		stack/stack_check.c \
		stack/stack_parsing.c \
		stack/stack_utils.c \
		utils/ft_split.c \
		utils/utils.c \
		main.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS_DIR}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re