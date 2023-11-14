/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:45:05 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/14 09:59:02 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_here_doc(char *here_doc)
{
	int	fd;

	fd = open(here_doc, O_RDONLY);
	if (fd == -1)
	{
		unlink(here_doc);
		ft_perror_exit("Here_doc error", 1);
	}
	dup2(fd, STDIN_FILENO);
	unlink(here_doc);
}

void	get_input(char *limiter)
{
	int		fd;
	char	*line;

	fd = open("here_doc", O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
	{
		unlink("here_doc");
		ft_perror_exit("Here_doc error", 1);
	}
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line)
			ft_perror_exit("GNL error", 1);
		if (ft_strlen(line) == (ft_strlen(limiter) + 1) && \
			ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd);
	open_here_doc("here_doc");
}
