# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 18:43:51 by zzetoun           #+#    #+#              #
#    Updated: 2024/07/15 18:43:54 by zzetoun          ###   ########.ae        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_strlen.c		\
		ft_printf.c		\
		ft_tolower.c	\
		ft_putpoint.c	\
		ft_putchar_fd.c	\
		ft_puthex_fd.c	\
		ft_putnbr_fd.c	\
		ft_putunbr_fd.c	\
		ft_putstr_fd.c 

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBC = ar rcs
LIB	= ranlib
RM = rm -fr

all : ${NAME}

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIB} ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
