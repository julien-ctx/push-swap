NAME = push_swap

NAME_CHECKER = checker

SRCS = main.c \
		$(addprefix stack_functions/, stack_utils.c ft_free_stack.c) \
		$(addprefix indexing_functions/, indexing_utils.c) \
		$(addprefix moves/, swap.c rotate.c reverse_rotate.c push.c) \
		$(addprefix 3_numbers/, sort_three_numbers.c) \
		$(addprefix 5_numbers/, sort_five_numbers.c) \
		$(addprefix big_numbers/, big_sort.c find_sequence.c check_max_value.c do_moves.c find_best_push.c prepare_stack_a.c) \

SRCS_CHECKER = $(addprefix checker_bonus/, checker.c push.c rotate.c reverse_rotate.c swap.c moves.c) \
				$(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) \

OBJS = $(SRCS:.c=.o)

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

bonus: $(NAME_CHECKER)

$(NAME): $(OBJS)
	@make bonus -C libft/
	@gcc $(CFLAGS) -o $(NAME) -L libft -lft $(SRCS)
	@echo "\n✅ $(GREEN)SUCCESS: $(NAME) has been created$(RESET)\n"

$(NAME_CHECKER): $(OBJS_CHECKER)
	@make bonus -C libft/
	@gcc $(CFLAGS) -o $(NAME_CHECKER) -L libft -lft $(SRCS_CHECKER)	
	@echo "\n✅ $(GREEN)SUCCESS: $(NAME_CHECKER) has been created$(RESET)\n"

clean:
	@rm -rf $(OBJS) $(OBJS_CHECKER)
	@make clean -C libft
	@echo "\n$(RED)SUCCESS: object files have been deleted$(RESET)"

fclean: clean
	@rm -rf $(NAME) $(NAME_CHECKER)
	@rm -rf libft/libft.a
	@echo "\n$(RED)SUCCESS: object files $(NAME) and $(NAME_CHECKER) have been deleted$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus
