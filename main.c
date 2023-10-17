/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/15 18:38:20 by patatoss         ###   ########.fr       */
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
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1) {
    perror("open input file");
    exit(EXIT_FAILURE);
}
	fd[1] = open(argv[4], O_WRONLY);
	if (fd[1] == -1) {
    perror("open output file");
    exit(EXIT_FAILURE);
}
	int	pid1;
	int	pid2;
	// char	**cmd1;
	// char	**cmd2;
	char	*cmd1[] = {"grep", "a1", NULL};
	char	*cmd2[] = {"wc", "-l", NULL};

	// cmd1 = ft_split(argv[2], ' ');

	// cmd2 = ft_split(argv[3], ' ');

	ft_printf("Before fork1\n");
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		if (execve("/usr/bin/grep", cmd1, NULL) == - 1)
		{
			perror("execve pid1");
        	exit(EXIT_FAILURE);
		}
	}
	//waitpid(pid1, NULL, 0);
	ft_printf("Before fork2\n");
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[WRITE_END]);
		close(fd[READ_END]);
		if (execve("/usr/bin/wc", cmd2, NULL) == -1)
		{
			perror("execve pid2");
        	exit(EXIT_FAILURE);
		}
	}
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	//waitpid(pid1, NULL, 0);
	//waitpid(pid2, NULL, 0);
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
