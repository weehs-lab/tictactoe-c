NAME	= tictactoe-c
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3
RM		= rm -f

SRC		= tictactoe.c interface.c utility.c main.c
OBJS	= $(SRC:.c=.o)
HEADER	= tictactoe.h interface.h utility.h

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

norminette:
	@norminette $(SRC) $(HEADER) | grep -Ev "INVALID_HEADER|GLOBAL_VAR_NAMING|USER_DEFINED_TYPEDEF|FORBIDDEN_STRUCT|STRUCT_TYPE_NAMING" || true

.PHONY:all clean fclean re norminette
