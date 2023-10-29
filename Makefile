# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 18:15:34 by tiaferna          #+#    #+#              #
#    Updated: 2023/10/29 10:52:04 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRCS = 	main.c			\
		ft_perror_exit.c\
		ft_strndup.c	\
		ft_strcmp.c		\
		ft_printf/ft_printf_putnbr.c	\
		ft_printf/ft_printf_putstr.c	\
		ft_printf/ft_printf.c			\
		ft_split.c						\
		ft_substr.c						\
		ft_env_paths.c					\
		ft_check_path.c					\
		ft_strjoin.c					\
		ft_strlen.c
		

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
