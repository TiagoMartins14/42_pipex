/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/12 21:59:48 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_pipex(argv);
	return (0);
}

void	ft_pipex(char **argv)
{
	int	fd[2];
	fd[0] = open(argv[4]);
	fd[1] = open(argv[1]);
	int	pid1;
	int	pid2;
	char	**cmd1;
	char	**cmd2;
	
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		if (execve(cmd1[0], cmd1[1], NULL) == -1)
			ft_printf("Could not execute execve");
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[WRITE_END]);
		close(fd[READ_END]);
		if (execve(cmd2[0], cmd2[1], NULL) == -1)
			ft_printf("Could not execute execve");
	}
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
