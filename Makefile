NAME = push_swap
LIBFT =	Libft/libft.a
CC = gcc
INC = -I ./
SRCS =	./main.c \
		./push_swap_utils.c \
		./operations.c
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
OBJS = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(INC) $(SRCS) -o $(NAME) $(LIBFT)
$(LIBFT):
	@make -C ./Libft
clean:
	@rm -rf $(OBJS) *.dSYM
	@make clean -C ./libft
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re : fclean $(NAME)