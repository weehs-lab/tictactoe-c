NAME	= tictactoe-c
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC		= 
OBJS	= $(SRC:.c=.o)
HEADER	= 

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
	@norminette $(SRC) $(HEADER) | grep -Ev "INVALID_HEADER|VARIABLE_NAMING_CONV" || true

.PHONY:all clean fclean re norminette
