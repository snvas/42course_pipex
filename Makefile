NAME	=	pipex
CC		= 	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

HEADER_SRCS	=	pipex.h
HEADER_DIR	=	includes/
HEADER 		=	$(addprefix $(SRCS_DIR), $(SRCS))
INCLUDE		=	-Ilibft -Iincludes

SRCS		=	pipex.c error.c free.c children.c
SRCS_DIR	=	src/
SRCS_PATH	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS	=	$(SRCS_PATH:.c=.o)

LIBFT		= 	libft.a

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_SRCS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_SRCS) $(INCLUDE) -o $(NAME) -Llibft -lft
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

$(LIBFT): 
	$(MAKE) bonus -C libft/

clean:
	$(RM) $(OBJ_SRCS)
	$(MAKE) clean -C libft/
	@echo -e "$(YELLOW)objects files deleted!$(DEFAULT)"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft/
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m