NAME	 =	get_next_line
COMP	 =	gcc
CFLAGS	 =	-Wall -Werror -Wextra -g
HEAD	=	.
SRC		=	get_next_line.c\
			get_next_line_utils.c\
			main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) $(CFLAGS) -o $@ -c $< -I $(HEAD)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) 

clean :
	@rm -f $(OBJ)


fclean : clean
	@rm -f $(NAME)

re : fclean all
	
.PHONY: all fclean clean re