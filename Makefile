# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:39:48 by malleman          #+#    #+#              #
#    Updated: 2023/03/15 17:05:37 by malleman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#-------------------------- SOURCES -------------------------------------------#
SRCS 		=	main.c init_and_parse.c checker_input.c create_stack.c \
				checker_size_and_order.c actions.c sort_3.c sort_4.c sort_5.c \
				big_sort.c free_fonctions.c

#--------------------------	VARIABLES -----------------------------------------#
NAME		= push_swap

OBJS		= ${SRCS:.c=.o}

CC			= gcc
CFLAGSDDBUG	= -Wall -Wextra -Werror -I. -Iincludes -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -I. -Iincludes -g3
#-------------------------- COMMANDES -----------------------------------------#
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: 	${NAME}

${NAME}: ${OBJS}
	make -C ./libft
	${CC} ${CFLAGS} ${SRCS} ${LIBFT} -o ${NAME} -Llibft -lft


clean :
		
		rm -f ${OBJS}
		make clean -C ./libft

fclean : clean
		rm -f ${NAME}
		make fclean -C ./libft

re: 	fclean all

.PHONY: all clean fclean re
