CC	:= gcc

RM	:= rm -rf

LDFLAGS	+= -L. -lmy

CFLAGS	+= -Iinclude

SRCS	:= $(shell find src -type f -name "*.c")

OBJS	:= $(SRCS:.c=.o)

NAME	:= eval_expr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
