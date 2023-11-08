# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 18:15:34 by tiaferna          #+#    #+#              #
#    Updated: 2023/11/08 11:42:28 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SRCDIR = src/mandatory

SRCBONDIR = src/bonus

INCDIR	=   includes

LIBFTDIR =  src/libft

SRCS = 	main.c							\
		ft_perror_exit.c				\
		ft_strndup.c					\
		ft_env_paths.c					\
		ft_check_path.c					\
		ft_execute.c					\
		ft_free_tab.c					\
		ft_split_paths.c				\
		ft_free_mem_buff.c

LIBS = -L$(LIBFTDIR) -lft

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
		@ $(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libft:
	@ cd $(LIBFTDIR) && make -s

%.o: %.c *.h
	@ $(CC) $(CFLAGS) -c $< -I . -o $@

clean:
		@ $(MAKE) -s -C $(LIBFTDIR) clean
		@ $(RM) $(OBJS)

fclean: clean
		@ $(MAKE) -s -C $(LIBFTDIR) fclean
		@ $(RM) $(NAME)
