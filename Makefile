BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/error_check.c $(SRC_DIR)/new_node.c \
$(SRC_DIR)/operations.c $(SRC_DIR)/double_operations.c \
$(SRC_DIR)/separate.c $(SRC_DIR)/sort_little.c $(SRC_DIR)/sort_all.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/main/%.o)

BONUS_SRC = $(BONUS_DIR)/checker.c $(BONUS_DIR)/error_check.c $(BONUS_DIR)/new_node.c \
$(BONUS_DIR)/operations.c $(BONUS_DIR)/double_operations.c $(BONUS_DIR)/read_input.c \
$(BONUS_DIR)/get_next_line.c $(BONUS_DIR)/get_next_line_utils.c
BONUS_OBJ = $(BONUS_SRC:$(BONUS_DIR)/%.c=$(OBJ_DIR)/bonus/%.o)

NAME = $(BIN_DIR)/push_swap
BONUS_NAME = $(BIN_DIR)/checker

all: $(NAME) $(BONUS_NAME)
	
man: $(NAME)

bonus: $(BONUS_NAME)

$(OBJ_DIR) $(BIN_DIR):
	@echo -e "$(CYAN)Creating directories...$(RESET)"
	mkdir -p $@

$(OBJ_DIR)/main $(OBJ_DIR)/bonus:
	@echo -e "$(CYAN)Creating main and bonus object directories...$(RESET)"
	mkdir -p $@

$(NAME): $(OBJ) | $(BIN_DIR)
	@echo -e "$(BLUE)Linking $(NAME)...$(RESET)"
	$(CC) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)$(BOLD)$(NAME) created successfully!$(RESET)"

$(BONUS_NAME): $(BONUS_OBJ) | $(BIN_DIR)
	@echo -e "$(BLUE)Linking $(BONUS_NAME)...$(RESET)"
	$(CC) $(BONUS_OBJ) -o $(BONUS_NAME)
	@echo -e "$(GREEN)$(BOLD)$(BONUS_NAME) created successfully!$(RESET)"

$(OBJ_DIR)/main/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)/main
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/bonus/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)/bonus
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(RED)Cleaning object files...$(RESET)"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "$(RED)Cleaning bin directory...$(RESET)"
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all man bonus clean fclean re
