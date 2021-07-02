NAME = push_swap
# CHECKER_NAME = checker
LIBFT =	Libft/libft.a
CC = gcc
INC = -I ./
SRCS = 	./push_swap_utils.c \
		./operations.c
FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
OBJS = $(SRCS:.c=.o)
all: $(NAME)
	
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(INC) $(SRCS) main.c -o $(NAME) $(LIBFT)
$(LIBFT):
	@make -C ./Libft
clean:
	@rm -rf $(OBJS) *.dSYM
	@make clean -C ./libft
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re : fclean $(NAME)
bonus: fclean $(LIBFT)
	gcc $(SRCS) checker.c $(FLAGS) $(INC) -o checker $(LIBFT)