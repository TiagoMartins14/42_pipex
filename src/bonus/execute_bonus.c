/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:18:27 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/10 12:41:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_in(char **argv, char **path_array, char **envp, int index)
{
	int		fd_in;
	char	*infile;
	char	*path;
	char	**cmds;

	cmds = ft_split(argv[index], ' ');
	path = check_path(cmds[0], path_array);
	infile = ft_check_infile(argv[1]);
	fd_in = open(infile, O_RDONLY);
	if (fd_in == -1)
		ft_perror_exit("Error fd_in\n", 1);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	if (!ft_strncmp(argv[1], "/dev/urandom", ft_strlen("/dev/urandom")))
	{
		unlink(infile);
		free(infile);
	}
	execve(path, cmds, envp);
	ft_perror_exit("Error execve.\n", COMMAND_NOT_FOUND);
}

void	execute_out(char **argv, char **path_array, char **envp, int i)
{
	int		fd_out;
	char	*path;
	char	**cmds;

	cmds = ft_split(argv[i- 1], ' ');
	path = check_path(cmds[0], path_array);
	fd_out = open(argv[i], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_out == -1)
		ft_perror_exit("Error fd_out\n", 1);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execve(path, cmds, envp);
	ft_perror_exit("Error.\n", COMMAND_NOT_FOUND);
}
