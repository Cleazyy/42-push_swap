# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:39:27 by fluchten          #+#    #+#              #
#    Updated: 2023/02/19 11:06:15 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

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
		utils/utils.c \
		main.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libs/libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/includes

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME}

clean:
	@make clean -C ${LIBFT_PATH}
	${RM} ${OBJS_DIR}

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re