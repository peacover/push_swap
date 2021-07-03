NAME = push_swap
CHECKER_NAME = checker
LIBFT =	Libft/libft.a
CC = @gcc
INC = -I ./
SRCS = 	./push_swap_utils.c \
		./push_swap_utils2.c \
		./push_swap_utils3.c \
		./init_sort.c \
		./operations.c \
		./operations2.c \
		./sort_five_nbs.c \
		./sort_three_nbs.c
CHECKER_SRCS = checker.c
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
all: $(NAME)
	
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(INC) $(SRCS) main.c -o $(NAME) $(LIBFT)
$(LIBFT):
	@make -C ./Libft
clean:
	@rm -rf $(OBJS) $(CHECKER_OBJS) *.dSYM
	@make clean -C ./libft
fclean: clean
	@rm -f $(NAME) $(CHECKER_NAME)
	@make fclean -C ./libft
re : fclean $(NAME)
bonus: $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(SRCS) $(CHECKER_SRCS) $(FLAGS) $(INC) -o $(CHECKER_NAME) $(LIBFT)