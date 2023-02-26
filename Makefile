PROG	= pipex
PROG_B	= pipex_bonus

# FILES AND OBJECTS MANDATORY
SRCS 	= srcs/main.c srcs/utils.c srcs/execute.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/main.c

# FILES AND OBJECTS BONUS
SRCS_B	=	srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
OBJS_B	=	${SRCS_B:.c=.o}
MAIN_B	=	srcs/pipex_bonus.c

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g 
HEADER	=	-Iincludes

# COLORS TO MAKE YOUR LIFE PRETTIER
BLUE	=	\033[1;34m
GREEN	=	\033[1;32m
RED		=	\033[1;31m
WHITE	=	\033[1;37m
END		=	\033[0m

.c.o:		%.o : %.c
			@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
			@echo "\n$(GREEN)---- $(BLUE)LIBFT $(GREEN)is compiled ---- $(END)"
			@make re -C ./libft
			@$(CC) ${OBJS} -Llibft -lft -o ${PROG}
			@echo "$(BLUE)Pipex $(GREEN)is compiled $(BLUE)(☞ﾟ∀ﾟ)☞ $(RED)♥$(END)\n"


bonus:		${PROG_B}

${PROG_B}:	${OBJS_B}
			@echo "\n$(GREEN)---- $(BLUE)LIBFT $(GREEN)is compiled ---- $(END)"
			@$(MAKE) -s -C ./libft
			@$(CC) ${OBJS_B} -Llibft -lft -o ${PROG_B}
			@echo "$(BLUE)Pipex bonus $(GREEN)is compiled $(BLUE)(☞ﾟ∀ﾟ)☞ $(RED)♥$(END)\n"

clean:
			@make clean -C ./libft
			@rm -rf ${OBJS} 
			@rm -rf ${OBJS} ${OBJS_B}
			@echo "\n(⌐■_■)--︻╦╤─ - - - $(RED)objects are deleted.$(END)"

fclean: 	clean
			@make fclean -C ./libft
			@rm -f $(NAME)
			@rm -f ${PROG}
			@echo "(⌐■_■)--︻╦╤─ - - - $(RED)executive is deleted.$(END)\n"

re:			fclean all

re_bonus:	fclean bonus

# execute:	./pipex file1.txt ls wc file2.txt && cat file2.txt

valgrind:	
			valgrind --leak-check=full --trace-children=yes --track-fds=yes ./pipex in lo catte out

test:	
		@echo "--------------------"
		@echo "-- TESTS EXAMPLES --"
		@echo "--------------------"
		@echo "-- TEST 1 --"
		@echo "ls"
		@echo "-- TEST 2 --"
		@echo "ls -la"
		@echo "-- TEST 3 --"
		@echo "test with path : /bin/ls"
		@echo "--- TEST 4 ---"
		@echo "unset PATH"
		@echo "./a.out file1.txt "ls -la"  cat file2.txt"

.PHONY: all clean fclean re re_bonus bonus

# tu a juste a rechercher POTH au lieu de PATH
# comme sa tu fait pas unset PATH et tu garde ton GCC
# et il trouve pas POTH
# tu a le meme résultat


# valgrind --leak-check=full ./pipex file1.txt ls wc file2.txt && cat file2.txt