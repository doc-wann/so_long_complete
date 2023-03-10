NAME = so_long
FLAGS             = -Wall -Wextra -Werror -g3
LIBXFLAGS         = -lmlx -lXext -lX11 -lm -lz

FILES =	slfl_*.c
FILES_B =	slflb_*.c

PATH_SRC	= ./src/
SRCS		= $(addprefix $(PATH_SRC), $(FILES))
OBJS		= $(FILES:.c=.o)

PATH_SRC_BONUS	= ./src_bonus/
SRCS_BONUS		= $(addprefix $(PATH_SRC_BONUS), $(FILES_B))
OBJS_BONUS		= $(FILES_B:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBXFLAGS)

$(OBJS): $(SRCS) ./src/astronaut.h
	cc $(FLAGS) -c $(SRCS)


bonus: so_long_bonus

so_long_bonus: $(OBJS_BONUS)
	cc $(FLAGS) -o so_long_bonus $(OBJS_BONUS) $(LIBXFLAGS)

$(OBJS_BONUS): $(SRCS_BONUS) ./src_bonus/astronaut.h
	cc $(FLAGS) -c $(SRCS_BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS) 

fclean:	clean
	rm -rf $(NAME) so_long_bonus

re:	fclean all

.PHONY: all clean fclean re
