CC=cc
CFLAGS=-Wall -Wextra -Werror

SRC_DIR = src

SRCS = $(SRC_DIR)/push_swap.c $(SRC_DIR)/error_check.c $(SRC_DIR)/new_node.c $(SRC_DIR)/operations.c $(SRC_DIR)/double_operations.c $(SRC_DIR)/is_sorted.c $(SRC_DIR)/separate.c $(SRC_DIR)/sort_little.c $(SRC_DIR)/sort_all.c

OBJS=$(SRCS:.c=.o)
NAME=push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
