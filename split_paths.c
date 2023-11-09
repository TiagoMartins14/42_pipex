/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:04:26 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/09 09:39:50 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_paths(char **paths)
{
	int		i;
	int		j;
	char	**paths_with_dash;

	i = 0;
	while (paths[i])
		i++;
	paths_with_dash = (char **)malloc(sizeof(char *) * (i + 1));
	paths_with_dash[i] = NULL;
	i = 0;
	while (paths[i])
	{
		j = 0;
		paths_with_dash[i] = malloc(sizeof(char) * (ft_strlen(paths[i]) + 2));
		while (paths[i][j])
		{
			paths_with_dash[i][j] = paths[i][j];
			j++;
		}
		paths_with_dash[i][j++] = '/';
		paths_with_dash[i][j] = '\0';
		i++;
	}
	ft_free_tab(paths);
	return (paths_with_dash);
}
