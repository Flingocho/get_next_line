############################################################################################################
# Variables

# Library name
NAME			= libgnl.a

# Directories
SRC_DIR			= src
INC_DIR			= include
OBJ_DIR			= obj

# Include files
INCLUDE			= $(INC_DIR)/get_next_line.h

# List of source files
SRCS_FILES		= get_next_line.c get_next_line_utils.c
					
# Complete paths					
SRCS			= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

# Objects
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compiler settings
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR)
LIB				= ar rcs

# Colors
GREEN			= \033[0;32m
UGREEN			= \033[4;32m
RED				= \033[0;31m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
CYAN			= \033[0;36m
NC				= \033[0m # No color

############################################################################################################
# Rules

all: ascii_art

ascii_art:
	@if ! $(MAKE) -q $(NAME); then \
		printf "$(CYAN)\n"; \
		printf "  ██████╗ ███╗   ██╗██╗     \n"; \
		printf " ██╔════╝ ████╗  ██║██║     \n"; \
		printf " ██║  ███╗██╔██╗ ██║██║     \n"; \
		printf " ██║   ██║██║╚██╗██║██║     \n"; \
		printf " ╚██████╔╝██║ ╚████║███████╗\n"; \
		printf "  ╚═════╝ ╚═╝  ╚═══╝╚══════╝\n"; \
		printf "           by jvidal-t\033[0m\n"; \
		echo "$(YELLOW)\nCreating library...$(GREEN)"; \
		$(MAKE) -s $(NAME); \
	else \
		echo "$(GREEN)[$(NAME)] is already up to date.$(NC)"; \
	fi

# Rule to build the library from object files
$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS) && \
	(printf "$(UGREEN)\n%s$(NC)" "[$(NAME)]"; printf "$(GREEN)%s$(NC)\n" " Compiled successfully.")

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@echo -n "█"
	@$(CC) $(CFLAGS) -c -o $@ $<

# Rule to remove all object files
clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(RED)%s$(NC)\n" "[$(NAME)] Object files cleaned."

# Rule to remove all generated files (objects and library)
fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)%s$(NC)\n" "[$(NAME)] Cleaned successfully."

# Rule to rebuild the project from scratch
re: fclean all

# Test rule to compile a simple test program
test: $(NAME)
	@$(CC) tests/test.c $(CFLAGS) -L. -lgnl -o test_gnl && \
	printf "$(GREEN)%s$(NC)\n" "Test program compiled. Run with ./test_gnl"

# Declaration of phony targets (not associated with files)
.PHONY: all ascii_art clean fclean re test
