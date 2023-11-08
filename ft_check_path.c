/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:46:18 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/08 12:53:07 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_path(char* cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*all_paths;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	all_paths = ft_env_paths(envp);
	paths = ft_split_paths(ft_split(all_paths, ':'));
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
			break ;
		//free(path);
		i++;
	}
	//ft_free_tab(paths);
	if (!path)
		ft_perror_exit("Error\n", 127);
	return (path);
}
