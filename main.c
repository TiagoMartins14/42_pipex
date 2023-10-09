/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/09 17:27:30 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	
}

void	ft_pipex(char **argv)
{
	int	fd[2];
	int	pid;
	
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		if (execve(argv[1], argv[2], NULL) == -1)
			ft_printf("Could not execute execve");
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		if (execve(argv[3], argv[4], NULL) == -1)
			ft_printf("Could not execute execve");
	}
}

char	**ft_argVec(char **argv, int i)
{
	char	**arguments;
	int		num_of_args;
	int		j;
	int		k;
	
	num_of_args = i;
	j = i;
	k = 0;
	while (ft_strcmp(argv[i], "|") != 0 && argv[i]);
		i++;
	num_of_args = i - num_of_args;
	arguments = (char **)malloc(sizeof(char *) * num_of_args + 1);
	while (j < i)
	{
		arguments[k] = ft_strdup(argv[j]);
		k++;
		j++;
	}
	return (arguments);
}
