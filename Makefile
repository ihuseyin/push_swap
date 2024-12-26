RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
BIN_DIR = bin

$(OBJ_DIR) $(BIN_DIR):
	@echo -e "$(CYAN)Creating directories...$(RESET)"
	mkdir -p $@

$(OBJ_DIR)/main $(OBJ_DIR)/bonus:
	@echo -e "$(CYAN)Creating main and bonus object directories...$(RESET)"
	mkdir -p $@

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/main/%.o)

BONUS_SRC = $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJ = $(BONUS_SRC:$(BONUS_DIR)/%.c=$(OBJ_DIR)/bonus/%.o)

NAME = $(BIN_DIR)/push_swap
BONUS_NAME = $(BIN_DIR)/checker

all: $(NAME) $(BONUS_NAME)
	
man: $(NAME)

bonus: $(BONUS_NAME)

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

.PHONY: all clean fclean re
