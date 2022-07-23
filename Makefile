CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c utils.c time.c death.c routine.c

OBJS = $(SRCS:.c=.o)
NAME = philo
HEADER = philo.h

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I $(HEADER)

${NAME}: ${OBJS}
	@$(CC) $(CFLAGS) $^ -o $@ -I $(HEADER)
	@echo "COMPILATION SUCCESSFUL"

all: ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
	@echo "TOUT EST PROPRE"