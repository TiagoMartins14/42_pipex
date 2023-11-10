/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_paths_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:18:27 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/10 11:48:35 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**create_path_array(char **env)
{
	int		i;
	char	*temp;
	char	*path;
	char	**path_array_w_dash;

	i = 0;
	path = NULL;
	while (env[i] && path == NULL)
		path = ft_strnstr(env[i++], "PATH=", 5);
	if (!path)
		ft_perror_exit("Could not find path.", 127);
	path_array_w_dash = ft_split(path + 5, ':');
	i = 0;
	while (path_array_w_dash[i])
	{
		temp = ft_strjoin(path_array_w_dash[i], "/");
		free(path_array_w_dash[i]);
		path_array_w_dash[i] = temp;
		i++;
	}
	return (path_array_w_dash);
}
