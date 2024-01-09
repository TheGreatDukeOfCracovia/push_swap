NAME = push_swap
SOURCES = main.c \
		  parser.c \
		  a_to_b.c \
		  b_to_a.c \
		  move_path.c \
		  lst_utils1.c \
		  lst_utils2.c \
		  sorting_utils1.c \
		  sorting_utils2.c \
		  error.c \
		  push.c \
		  swap.c \
		  rotate.c \
		  reverse_rotate.c
OBJECTS = $(SOURCES:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

LIBDIR = libft
LIBFT = libft.a

BONUS_NAME = checker
BONUS_SOURCES = checker.c \
				parser.c \
				error.c\
				push.c \
				swap.c \
				rotate.c \
				reverse_rotate.c \
				sorting_utils1.c \
				lst_utils1.c \
				lst_utils2.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(LIBDIR)
	$(CC) $(OBJECTS) -o $(NAME) -L $(LIBDIR) -l:$(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUS_OBJECTS)
	make -C $(LIBDIR)
	$(CC) $(BONUS_OBJECTS) -o $(BONUS_NAME) -L $(LIBDIR) -l:$(LIBFT)

clean :
	make clean -C $(LIBDIR)
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean : clean
	make fclean -C $(LIBDIR)
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all bonus clean fclean re
