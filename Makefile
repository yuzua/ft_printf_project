NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = convert_base.c ft_printf.c libft_extension.c write_option_char.c write_option_number.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

# $(NAME): $(OBJS) $(LIBFT)
# 	ar rcs $(NAME) $(OBJS) $(LIBFT)
$(NAME): $(OBJS) $(LIBFT)
	@mkdir -p tmp_libft_objs
	@cd tmp_libft_objs && ar x ../$(LIBFT)
	ar rcs $(NAME) $(OBJS) tmp_libft_objs/*.o
	@rm -rf tmp_libft_objs

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re