NAME = libgetfile.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = ./Includes/ft_get_file
INCLUDES = -I$(INC_DIR)
OBJS_DIR = Objs
SRCS_DIR = $(shell find Srcs -type d)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRC = ft_get_file.c get_next_line.c get_next_line_utils.c
OBJS = $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo "Libgetfile finished compiling :D"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean