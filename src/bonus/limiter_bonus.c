/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:45:05 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/13 17:28:58 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*check_limiter(char *str, char* argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	read
}

int	create_here_doc(char **argv)
{
	int	fd;
	int	pipe_fd[2];
	int pid;
	
	if (pipe(pipe_fd) == -1)
		ft_perror_exit("Error.\n", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror_exit("Error.\n", 1);
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	
	
}
