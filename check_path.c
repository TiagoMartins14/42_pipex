/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:46:18 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/09 13:00:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*all_paths;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	all_paths = ft_env_paths(envp);
	paths = ft_split_paths(ft_split(all_paths, ':'));
	free(all_paths);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			break ;	
		i++;
	}
/* 	if (access(path, F_OK | X_OK) != 0)
		ft_perror_exit("Error\n", 127); */
	return (path);
}
