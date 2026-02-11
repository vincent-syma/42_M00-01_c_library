NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar rcs

SRC_DIR = src
OBJ_DIR = temp
INC_DIR = include
INCLUDES = -I$(INC_DIR)

SRC := $(shell find $(SRC_DIR) -name "*.c")

# --- colours ---
RESET := \033[0m
BOLD  := \033[1m
RED   := \033[31m
GRN   := \033[32m
YEL   := \033[33m
BLU   := \033[34m

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
		@printf "$(BLU)Libft.a has been created.$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "CC %-35s" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ && \
		printf "[$(GRN)OK$(RESET)]\n" || \
		(printf "[$(RED)FAIL$(RESET)]\n"; exit 1)

all: $(NAME)

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLU)Libft objects have been deleted.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(BLU)Libft has been deleted.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re