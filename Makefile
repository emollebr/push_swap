# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emollebr <emollebr@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 13:23:07 by emollebr          #+#    #+#              #
#    Updated: 2023/08/02 13:23:09 by emollebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := push_swap
CFLAGS  := -Wall -Wextra -Werror
LIBFTFLAGS := -Imy_lib -Lmy_lib
LIBFT := ./my_lib/
LIBS := $(LIBFT)/my_lib.a
SRCS    := main.c push_swap.c sortfun.c stackfun.c utils.c
OBJS    := $(SRCS:.c=.o)
################################################################################

all:    libft ${NAME}

${NAME}:	${OBJS} ${LIBS}
	cc $^ ${LIBFTFLAGS} -o ${NAME}

libft:
	make -C ${LIBFT}

.c.o:   ${SRCS}
	cc ${CFLAGS} -I. -Imy_lib -c -o $@ $<

clean:
	   rm -f ${OBJS} && cd ./my_lib && make clean

fclean:
	   rm -f ${NAME} ./my_lib/my_lib.a

re: clean all

.PHONY:     all clean fclean re
