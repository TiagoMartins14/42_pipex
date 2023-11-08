/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:19:48 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/06 12:29:13 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_mem_buff(char *buffer, char *path, int fd)
{
	if (buffer)
		free(buffer);
	if (path)
		free(path);
	if (fd != -1)
		close(fd);
	perror(NULL);
	exit(EXIT_FAILURE);
}
