# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:39:27 by fluchten          #+#    #+#              #
#    Updated: 2023/01/17 11:42:19 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC_DIR = -I includes

SRCS_DIR = srcs
SRCS = args.c \
		main.c \
		utils.c

OBJS = $(addprefix ${SRCS_DIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INC_DIR} ${FT_PRINTF_INC} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re