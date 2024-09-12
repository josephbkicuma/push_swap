NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
LIBFT_DIR = libs/libft
OBJ_DIR = objs
INCLUDE_DIR = includes

SRCS = $(SRC_DIR)/push_swap.c \
       $(SRC_DIR)/error.c \
       $(SRC_DIR)/free.c \
       $(SRC_DIR)/init_stack.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/operations/push.c \
       $(SRC_DIR)/operations/reverse_rotate.c \
       $(SRC_DIR)/operations/rotate.c \
       $(SRC_DIR)/operations/swap.c \
       $(SRC_DIR)/sort/cost.c \
       $(SRC_DIR)/sort/get_cheapest.c \
       $(SRC_DIR)/sort/set_target.c \
       $(SRC_DIR)/sort/small_sort.c \
       $(SRC_DIR)/sort/sort_stack_a.c \
       $(SRC_DIR)/sort/sort_stack_b.c \
       $(SRC_DIR)/sort/target.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
