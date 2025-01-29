SRCS := ./operations/push_ops.c ./operations/rev_rotate_ops.c ./operations/rotate_ops.c ./operations/swap_ops.c \
./parser/parser.c \
./set/set_op.c ./set/set.c \
./sort/merge_sort.c ./sort/sort_large.c ./sort/sort.c ./sort/sort1.c \
./stack/utils.c ./stack/utils1.c ./stack/utils2.c \
./utils/helpers.c ./utils/helpers1.c
OBJS := $(SRCS:.c=.o)

SRCS_BONUS= ./bonus/main_bonus.c ./gnl/get_next_line_utils.c ./gnl/get_next_line.c
OBJ_BONUS= $(SRCS_BONUS:.c=.o)

NAME=push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME):all

all: $(OBJS) main.o
	$(CC) $(CFLAGS) $^  -o $(NAME)

clean:
	rm -rf $(OBJS) $(OBJ_BONUS) main.o ./bonus/main_bonus.o

fclean: clean
	rm -rf $(NAME) checker

re: fclean all

bonus: $(OBJS) $(OBJ_BONUS) ./bonus/main_bonus.o
	$(CC) $(CFLAGS) $^  -o checker

.PHONY: all clean fclean re bonus
