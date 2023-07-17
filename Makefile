# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emollebr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:04:01 by emollebr          #+#    #+#              #
#    Updated: 2023/07/17 12:11:56 by emollebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CFLAGS	:= -Wall -Wextra -Werror
LIBFTFLAGS := -Imy_lib -Lmy_lib
LIBFT := ./my_lib/
LIBS := $(LIBFT)/my_lib.a
SRCS	:= main.c ops.c do_ps.c do_r.c
OBJS	:= $(SRCS:.c=.o)

################################################################################

all:	libft ${NAME}

${NAME}:  ${OBJS} ${LIBS} 
	 cc $^ ${LIBFTFLAGS} -o ${NAME} 

libft: 
	make -C ${LIBFT}
	
.c.o:	${SRCS}
	cc -I. -Imy_lib -c -o $@ $<	 

clean:
	rm -f ${OBJS} && cd ./my_lib && make clean

fclean:
	rm -f ${NAME} ./my_lib/my_lib.a

re:	clean all

.PHONY:		all clean fclean re
