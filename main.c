/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:25:50 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/09 18:52:52 by tiaferna         ###   ########.fr       */
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
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		// if (execve(argv[1], ft_arg_vec(&argv[2], 2), NULL) == -1)
		// 	ft_printf("Could not execute execve");
		if (execve(argv[1], ft_split(argv[2], ' '), NULL) == -1)
			ft_printf("Could not execute execve");
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		// if (execve(argv[3], ft_arg_vec(&argv[4], 4), NULL) == -1)
		// 	ft_printf("Could not execute execve");
		if (execve(argv[3], ft_split(argv[4], ' '), NULL) == -1)
			ft_printf("Could not execute execve");
		wait(NULL);
	}
}

char	**ft_arg_vec(char **argv, int i)
{
	char	**arguments;
	int		num_of_args;
	int		j;
	int		k;

	num_of_args = i;
	j = i;
	k = 0;
	while (ft_strcmp(argv[i], "|") != 0 && argv[i])
		i++;
	num_of_args = i - num_of_args;
	arguments = (char **)malloc(sizeof(char *) * num_of_args + 1);
	while (j < i)
	{
		arguments[k] = ft_strdup((const char *)argv[j]);
		k++;
		j++;
	}
	return (arguments);
}
