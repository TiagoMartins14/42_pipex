/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:19:43 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/02 10:00:26 by patatoss         ###   ########.fr       */
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
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			all_paths = ft_strndup(envp[i], 5);
			return (all_paths);
		}
		i++;
	}
	ft_perror_exit("No PATH found\n", 127);
	return ("Error");
}
