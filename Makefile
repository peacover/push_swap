NAME = push_swap
LIBFT =	Libft/libft.a
CC = gcc
INC = -I ./
SRCS =	./main.c \
		./push_swap_utils.c 
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
OBJS = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(INC) $(SRCS) -o $(NAME) $(LIBFT)
$(LIBFT):
	@make -C ./Libft
clean:
	@rm -rf $(OBJS)
	@make clean -C ./libft
fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
re : fclean $(NAME)