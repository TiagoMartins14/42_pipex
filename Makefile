# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 18:15:34 by tiaferna          #+#    #+#              #
#    Updated: 2023/11/10 18:46:57 by patatoss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NC		= \033[0m
BOLD	= \033[1m
ULINE	= \033[4m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SRCDIR = src/mandatory

SRCBONDIR = src/bonus

LIBFTDIR =  src/libft

SRCS = 	src/mandatory/pipex.c src/mandatory/checkers.c src/mandatory/execute.c src/mandatory/memory_frees.c \
		src/mandatory/split_paths.c

BONUS_SRCS = src/bonus/checkers_bonus.c src/bonus/pipex_bonus.c src/bonus/execute_bonus.c src/bonus/memory_frees_bonus.c \
			src/bonus/split_paths_bonus.c

LIBS = -L$(LIBFTDIR) -lft

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	clear
	@echo "$(GREEN)./pipex executable is ready!$(NC)"

bonus: libft $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(NAME)
	clear
	@echo "$(GREEN)./pipex with $(YELLOW)bonus $(GREEN)executable is ready!$(NC)"

libft:
	cd $(LIBFTDIR) && make

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -I . -o $@

clean:
	$(MAKE) -s -C $(LIBFTDIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS)
	clear
	@echo "$(RED)Object files have been deleted!$(NC)"

fclean: clean
	$(MAKE) -s -C $(LIBFTDIR) fclean
	$(RM) $(NAME) $(BONUS)
	clear
	@echo "$(RED)Object files and executable have been deleted!$(NC)"

re: fclean all

.PHONY: all clean fclean re