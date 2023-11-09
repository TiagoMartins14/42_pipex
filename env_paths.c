/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:19:43 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/09 09:23:36 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_env_paths(char **envp)
{
	int		i;
	char	*all_paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			all_paths = ft_strndup(envp[i], 5);
			return (all_paths);
		}
		i++;
	}
	ft_perror_exit("No PATH found\n", 127);
	return ("Error");
}
