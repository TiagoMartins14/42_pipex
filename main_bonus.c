/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:33:47 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/07 13:32:45 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char** varp)
{
/* 	int	i;
	char	**cmd1;
	char	**cmd2;
	char	***all_cmds;
	
	i = 2;
	if (ft_strcmp(argv[1], "here_doc" == 0))
	{
		
	}
	else if (argc >= 5)
	{
		while (i < argc)
		{
			cmd1 = ft_split(argv[i], ' ');
			cmd2 = ft_split(argv[i + 1], ' ');
			ft_pipex(argv, envp, cmd1, cmd2);
		}
	}
	perror("Invalid input\n"); */
	check_all_paths(argc, argv, envp);
	return (COMMAND_NOT_FOUND);
}

void	ft_pipex_bonus(int argc, char **argv, char **envp)//, char **cmd1, char **cmd2)
{
	int		fd_pipe[2];
	int		pid1;
	char	*path1;
	char	*path2;
	char	***all_cmds;

	if (pipe(fd_pipe) == -1)
	{
		ft_free_all_tabs(cmd1, cmd2);
		ft_perror_exit("Error\n", 1);
	}
	all_cmds = all_cmds(argc, argv);
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
