# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 18:15:34 by tiaferna          #+#    #+#              #
#    Updated: 2023/11/03 10:10:22 by patatoss         ###   ########.fr        #
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
		ft_strcmp.c						\
		ft_printf/ft_printf_putnbr.c	\
		ft_printf/ft_printf_putstr.c	\
		ft_printf/ft_printf.c			\
		libft/ft_split.c				\
		libft/ft_substr.c				\
		ft_env_paths.c					\
		ft_check_path.c					\
		libft/ft_strjoin.c				\
		libft/ft_strlen.c				\
		ft_execute.c					\
		ft_free_tab.c					\
		ft_split_paths.c				\
		ft_free_mem_buff.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -I . -o $@

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)
