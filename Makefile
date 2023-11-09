# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 18:15:34 by tiaferna          #+#    #+#              #
#    Updated: 2023/11/09 11:35:17 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

RESET   = \033[0m
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

INCDIR	=   includes

LIBFTDIR =  src/libft

SRCS = 	main.c						\
		perror_exit.c				\
		ft_strndup.c				\
		env_paths.c					\
		check_path.c				\
		execute.c					\
		free_tab.c					\
		split_paths.c				\
		free_mem_buff.c				\
		check_infile.c

LIBS = -L$(LIBFTDIR) -lft

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	clear
	@echo "$(GREEN)./pipex executable is ready!$(RESET)"
		
libft:
	cd $(LIBFTDIR) && make

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -I . -o $@

clean:
	$(MAKE) -s -C $(LIBFTDIR) clean
	$(RM) $(OBJS)
	clear
	@echo "$(RED)object files have been deleted!$(RESET)"

fclean: clean
	$(MAKE) -s -C $(LIBFTDIR) fclean
	$(RM) $(NAME)
	clear
	@echo "$(RED)object files and executable have been deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re