# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 15:12:26 by mchampag          #+#    #+#              #
#    Updated: 2022/10/31 12:51:34 by mchampag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libft.a
SRCS 	=	ft_memcpy.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
			ft_strjoin.c ft_strlen.c ft_strnstr.c
OBJS 	=	${SRCS:.c=.o}
HEADER	=	./

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c
			@${CC} ${CFLAGS} -I ${HEADER} -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
			@ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			@rm -f ${OBJS}

fclean: 	clean
			@rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re