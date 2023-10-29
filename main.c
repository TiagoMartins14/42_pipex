/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/29 10:06:57 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
/* 		char **cmd1 = ft_split(argv[2], ' ');
		ft_printf("%s\n", ft_check_path(cmd1[0]));
		ft_printf("%s\n", ft_paths_environment()); */
		ft_pipex(argv);
	}
	return (0);
}

void	ft_pipex(char **argv)
{
	int		fd[2];
	int		fd_temp;
	int		pid1;
	char	**cmd1;
	char	**cmd2;
	
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	char	*path1 = ft_check_path(cmd1[0]);
	char	*path2 = ft_check_path(cmd2[0]);
	if (pipe(fd) == -1)
		ft_perror_exit();
	fd[READ_END] = open(argv[1], O_RDONLY);
	if (fd[READ_END] == -1)
		ft_perror_exit();
	fd[WRITE_END] = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (fd[WRITE_END] == -1)
		ft_perror_exit();
	pid1 = fork();
	if (pid1 == -1)
		ft_perror_exit();
	if (pid1 == 0)
	{
		fd_temp = open("temp.txt", O_RDWR | O_CREAT, 0777);
		if (fd_temp == -1)
			ft_perror_exit();
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		dup2(fd_temp, STDOUT_FILENO);
		close(fd_temp);
		execve(path1, cmd1, NULL);
		exit(EXIT_FAILURE);
	}
	waitpid(pid1, NULL, 0);
	fd_temp = open("temp.txt", O_RDWR | O_CREAT, 0777);
	if (fd_temp == -1)
		ft_perror_exit();
	dup2(fd_temp, STDIN_FILENO);
	close(fd_temp);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	close(fd[READ_END]);
	execve(path2, cmd2, NULL);
	exit(EXIT_FAILURE);
}

char	*ft_paths_environment()
{
	int	fd_paths;
	int	pid;
	char *cmd[4] = {"sh", "-c", "echo $PATH", NULL};
	
	pid = fork();
	if (pid == -1)
	{
		perror("Error 6\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		fd_paths = open("paths.txt", O_RDWR | O_CREAT, 0777);
		dup2(fd_paths, STDOUT_FILENO);
		close(fd_paths);
		execve("/bin/sh", cmd, NULL);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	fd_paths = open("paths.txt", O_RDWR | O_CREAT, 0777);
	dup2(fd_paths, STDIN_FILENO);
	close(fd_paths);
	return (get_next_line(STDIN_FILENO));
}

char	*ft_check_path(char* cmd)
{
	int		i;
	char	**paths;
	char	*path;
	char	*all_paths;

	all_paths = ft_paths_environment();
	paths = ft_split(all_paths, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		i++;
	}
	return ("Invalid command\n");
}
