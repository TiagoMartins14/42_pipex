/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:19:48 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/08 11:57:59 by tiaferna         ###   ########.fr       */
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
	exit(1);
}
