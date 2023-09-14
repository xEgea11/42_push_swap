NAME = push_swap

INCLUDES = -I ./include/ ./libft/include/
INCLUDE_DIR = include/

CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRC_DIR = src/
FILES = main.c list_utils.c list_delete.c list_insert.c input_utils.c print_util.c \
		swap_actions.c push_actions.c rotate_actions.c reverse_rotate_actions.c \
		input_modes.c find_value_idx.c order_list.c algorithm.c list_utils_2.c \
		costs_combined.c push_swap.c pop_actions.c shortest_rotation.c insert_order.c

SRC_FILES = $(addprefix $(SRC_DIR), $(FILES))

OBJ_DIR = obj/
OBJS_FILES = $(FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJS_FILES))

DOTH = push_swap.h 

INCLUDE = $(addprefix $(INCLUDE_DIR), $(DOTH))

LIB_DIR = libft/

LIB = libft.a

LIBFT = $(addprefix $(LIB_DIR), $(LIB))

# Colores
RESET = "\033[0;m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"

$(NAME) :  $(OBJ_DIR) $(OBJS) $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	@echo $(GREEN) [*] Push_swap compiled! $(RESET)
	@sleep 1

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR) 
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(YELLOW) [*] Generating $@ ... $(RESET)

$(LIBFT) : 
	@make -C $(LIB_DIR)

$(OBJ_DIR) : 
	@mkdir -p $(OBJ_DIR)
	@echo $(GREEN) [*] Objects file of push_swap created! $(RESET)
	@sleep 1


.PHONY : all clean fclean re

all : $(NAME)

clean :
	@echo $(GREEN) [*] Removing objects from push_swap... $(RESET)
	@sleep 1
	@rm -f $(SRC_OBJS)

	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf "$(OBJ_DIR)"; \
	fi 
	@echo $(GREEN) [*] Objects from push_swap removed! $(RESET)
	@sleep 1
	@make -C libft/ fclean
	

fclean : clean
	@rm -f $(NAME)
	@echo $(GREEN) [*] Binary push_swap removed! $(RESET)
	@sleep 1


re : fclean all 
