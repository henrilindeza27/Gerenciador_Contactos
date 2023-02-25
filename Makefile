SOURCEFILES	= $(wildcard ./srcs/C/*.c)
OBJECTS	= ${SOURCEFILES:.c=.o}
NAME	= ppt_exec
COMPILER		= cc
RM		= rm -f
FLAGS = -Wall -Wextra -Werror -Isrcs/libs


.PHONY: all, clean, fclean, re, exec

all: exec

exec: ${NAME}
	./${NAME}


${NAME} : ${OBJECTS}
	@echo ${SOURCEFILES}
	${COMPILER} ${FLAGS} -o $@ $^

%.o : %.c
	${COMPILER} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all
