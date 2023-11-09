/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/09 13:00:21 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**cmd1;
	char	**cmd2;
/* 	char *var;

	var = ft_check_path("grepa", envp);
	ft_printf("%s\n", var);
	
	(void)cmd1;
	(void)cmd2;
	(void)argv;
	(void)argc; */
	if (argc == 5)
	{
		cmd1 = ft_split(argv[2], ' ');
		cmd2 = ft_split(argv[3], ' ');
		ft_pipex(argv, envp, cmd1, cmd2);
	}
	perror("Invalid input\n");
	return (COMMAND_NOT_FOUND);
}

void	ft_pipex(char **argv, char **envp, char **cmd1, char **cmd2)
{
	int		fd_pipe[2];
	int		pid1;
	char	*path1;
	char	*path2;

	if (pipe(fd_pipe) == -1)
	{
		ft_free_all_tabs(cmd1, cmd2);
		ft_perror_exit("Error\n", 1);
	}
	path1 = ft_check_path(cmd1[0], envp);
	path2 = ft_check_path(cmd2[0], envp);
	pid1 = fork();
	if (pid1 == -1)
	{
		free(path1);
		free(path2);
		ft_free_all_tabs(cmd1, cmd2);
		ft_perror_exit("Error\n", 1);
	}
	if (pid1 == 0)
		ft_execute_in(argv, path1, cmd1, fd_pipe);
	waitpid(pid1, NULL, 0);
	ft_execute_out(argv, path2, cmd2, fd_pipe);
}
