/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:46:56 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/08 11:58:33 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_in(char **argv, char *path1, char **cmd1, int *fd_pipe)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		ft_perror_exit("Error\n", 1);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);
	close(fd_pipe[READ_END]);
	close(fd_in);
	execve(path1, cmd1, NULL);
	free(path1);
	ft_free_tab(cmd1);
	ft_perror_exit("Error\n", COMMAND_NOT_FOUND);
}

void	ft_execute_out(char **argv, char *path2, char **cmd2, int *fd_pipe)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_out == -1)
		ft_perror_exit("Error\n", 1);
	dup2(fd_pipe[READ_END], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);
	close(fd_pipe[READ_END]);
	close(fd_out);
	execve(path2, cmd2, NULL);
	free(path2);
	ft_free_tab(cmd2);
	ft_perror_exit("Error\n", COMMAND_NOT_FOUND);
}
