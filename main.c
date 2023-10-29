/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/29 11:51:50 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
/* 		ft_printf("%s\n", ft_env_paths(envp));
		char **cmd1 = ft_split(argv[2], ' ');
		ft_printf("%s\n", ft_check_path(cmd1[0]));
		ft_printf("%s\n", ft_paths_environment()); */
		ft_pipex(argv, envp);
	}
	return (0);
}

void	ft_pipex(char **argv, char **envp)
{
	int		fd[2];
	int		pid1;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	path1 = ft_check_path(cmd1[0], envp);
	path2 = ft_check_path(cmd2[0], envp);
	if (pipe(fd) == -1)
		ft_perror_exit("Error\n");
	fd[READ_END] = open(argv[1], O_RDONLY);
	if (fd[READ_END] == -1)
		ft_perror_exit("Error\n");
	dup2(fd[READ_END], STDIN_FILENO);
	pid1 = fork();
	if (pid1 == -1)
		ft_perror_exit("Error\n");
	if (pid1 == 0)
	{

		// dup2(fd[READ_END], STDIN_FILENO);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[READ_END]);
		close(fd[WRITE_END]);

		execve(path1, cmd1, NULL);
		exit(EXIT_FAILURE);
	}
	waitpid(pid1, NULL, 0);
	fd[WRITE_END] = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (fd[WRITE_END] == -1)
		ft_perror_exit("Error\n");
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	close(fd[READ_END]);
	execve(path2, cmd2, NULL);
	exit(EXIT_FAILURE);
}
