/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:33:47 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/09 11:47:31 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char** envp)
{
	
/* 	int	i;
	char	**cmd1;
	char	**cmd2;
	char	***all_cmds;
	
	i = 2;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		
	}
	cmd1 = ft_split(argv[i], ' ');
	cmd2 = ft_split(argv[i + 1], ' ');
	ft_pipex(argv, envp, cmd1, cmd2);
	if (argc > 5)
	{
		i = 4
		while (i < argc)
		{
			cmd1 = ft_split(argv[i], ' ');
			ft_pipex_bonus(argv, envp, cmd1);
		}
		i++;
	}
	perror("Invalid input\n"); */
	check_all_paths(argc, argv, envp);
	return (COMMAND_NOT_FOUND);
}

void	ft_pipex_bonus(int argc, char **argv, char **envp, char **cmd1)
{
	int		fd_pipe[2];
	int		pid1;
	char	*path;

	if (pipe(fd_pipe) == -1)
	{
		ft_free_tab(cmd1);
		ft_perror_exit("Error\n", 1);
	}
	path = ft_check_path(cmd1[0], envp);
	pid1 = fork();
	if (pid1 == -1)
	{
		free(path);
		ft_free_tab(cmd1);
		ft_perror_exit("Error\n", 1);
	}
	if (pid1 == 0)
		ft_execute_in(argv, path1, cmd1, );
	waitpid(pid1, NULL, 0);
	ft_execute_out(argv, path2, cmd2, fd_pipe);
}

char	***all_cmds(int argc, char **argv)
{
	int		i;
	char	***all_cmds;
	
	i = 1;
	all_cmds = (char ***)malloc(sizeof(char**) * argc - 2);
	while (++i < argc)
		all_cmds[i - 2] = ft_split(argv[i]);
	all_cmds[i] = NULL;
	return (NULL);
}

void	check_all_paths(int argc, char **argv, char **envp)
{
	char	**cmd;
	int		i;

	i = 2;
	cmd = ft_split(argv[i], ' ');
	while (ft_check_path(cmd[0], envp) && i < argc - 1)
		cmd = ft_split(argv[++i], ' ');
	return ;
}
