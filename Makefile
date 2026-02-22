NAME	= tictactoe-c
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRC		= 
OBJS	= $(SRCS:.c=.o)
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

.PHONY:all clean fclean re	
