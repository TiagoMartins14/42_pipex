/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:19:43 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/29 10:43:03 by tiaferna         ###   ########.fr       */
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
	ft_printf("No PATH found\n");
	exit(EXIT_FAILURE);
	return ("Error");
}
