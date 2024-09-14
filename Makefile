NAME = push_swap
BONUS_NAME = push_swap_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
BONUS_DIR = bonus
LIBFT_DIR = libs/libft
OBJ_DIR = objs
BONUS_OBJ_DIR = bonus_objs
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

BONUS_SRCS = $(BONUS_DIR)/main.c \
             $(BONUS_DIR)/lib_utils/ft_atol.c \
             $(BONUS_DIR)/lib_utils/ft_isdigit.c \
             $(BONUS_DIR)/lib_utils/ft_strcmp.c \
             $(BONUS_DIR)/lib_utils/ft_putstr_fd.c \
             $(BONUS_DIR)/lib_utils/ft_split.c \
             $(BONUS_DIR)/lib_utils/get_next_line.c \
             $(BONUS_DIR)/operations/push.c \
             $(BONUS_DIR)/operations/reverse_rotate.c \
             $(BONUS_DIR)/operations/rotate.c \
             $(BONUS_DIR)/operations/swap.c \
             $(BONUS_DIR)/utils/init_stack.c \
             $(BONUS_DIR)/utils/utils.c \
             $(BONUS_DIR)/utils/error.c \
             $(BONUS_DIR)/utils/free.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
