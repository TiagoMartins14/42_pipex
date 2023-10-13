/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/13 13:25:27 by tiaferna         ###   ########.fr       */
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
	pipe(fd);
	fd[0] = open(argv[4], O_RDONLY);
	fd[1] = open(argv[1], O_WRONLY);
	int	pid1;
	int	pid2;
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(argv[1], ' ');

	cmd2 = ft_split(argv[3], ' ');
	int	i = 1;
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		execve(ft_check_path("/nfs/homes/tiaferna/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", cmd1[0]), &cmd1[i], NULL);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[WRITE_END]);
		close(fd[READ_END]);
		execve(ft_check_path("/nfs/homes/tiaferna/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", cmd2[0]), &cmd2[i], NULL);
	}
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

char	*ft_check_path(char *all_paths, char* cmd)
{
	int		i;
	char	**paths;
	char	*path;
		
	paths = ft_split(all_paths, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(&path[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		i++;
	}
	return ("invalid");
}
