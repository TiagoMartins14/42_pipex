/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/17 12:51:34 by tiaferna         ###   ########.fr       */
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
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
		
	fd[READ_END] = open(argv[1], O_RDONLY);
	if (fd[READ_END] == -1)
	{
    	perror("could not open input file");
    	exit(EXIT_FAILURE);
	}
	
	fd[WRITE_END] = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (fd[WRITE_END] == -1)
	{
		perror("could not open or create output file");
		exit(EXIT_FAILURE);
	}

	int		fd_temp;
	int		pid1;
	int		pid2;
	char	**cmd1;
	char	**cmd2;
		
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');

	pid1 = fork();
	if (pid1 == 0)
	{
		fd_temp = open("temp.txt", O_RDWR | O_CREAT, 0777);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		
		dup2(fd_temp, STDOUT_FILENO);
		close(fd_temp);
		execve("/usr/bin/grep", cmd1, NULL);
		perror("Failed to execute execve pid1");
		exit(EXIT_FAILURE);
	}
	waitpid(pid1, NULL, 0);
	pid2 = fork();
	if (pid2 == 0)
	{
		fd_temp = open("temp.txt", O_RDWR | O_CREAT, 0777);
		dup2(fd_temp, STDIN_FILENO);	ft_printf("Before fork2\n");
		close(fd_temp);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		close(fd[READ_END]);
		execve("/usr/bin/wc", cmd2, NULL);
		perror("Failed to execute execve pid2");
		exit(EXIT_FAILURE);
	}
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	close(fd_temp);
	waitpid(pid2, NULL, 0);
}

char	*ft_paths_environment()
{
	int	fd;
	int	pid;
	pid = fork();
	if (pid == - 1)
		return (1);
	if (pid == 0)
	{
		fd = open(fd, STDOUT_FILENO);
		if (fd = -1)
			return (2);
		close(fd);
        char *const cmd[] = {"sh", "-c", "echo $PATH", NULL};
		execve("/bin/sh", cmd, NULL);
		perror("Failed to run execve");
        exit(EXIT_FAILURE);
	}
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
		path = ft_strjoin(paths[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		i++;
	}
	return ("invalid");
}
