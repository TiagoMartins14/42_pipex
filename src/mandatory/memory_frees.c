/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_frees.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:40:17 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/10 11:14:14 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return ;
}

void	free_array_and_exit(char **array, char *error)
{
	ft_free_array(array);
	perror(error);
}

void	ft_perror_exit(char *str, int error)
{
	perror(str);
	exit(error);
}

void	free_mem_buff(char *buffer, char *path, int fd)
{
	if (buffer)
		free(buffer);
	if (path)
		free(path);
	if (fd != -1)
		close(fd);
	perror(NULL);
	exit(1);
}
