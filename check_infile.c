/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:43 by patatoss          #+#    #+#             */
/*   Updated: 2023/11/09 09:18:06 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_infile(char **argv)
{
	if (ft_strncmp(argv[1], "/dev/urandom", ft_strlen("/dev/urandom")) == 0)
		return (ft_urandom_infile());
	else
		return (argv[1]);
}

char	*ft_urandom_infile(void)
{
	char	*buffer;
	char	*buffer_path;
	int		buffer_fd;

	buffer = urand_buffer();
	buffer_path = ft_strdup("/tmp/pipex_buffer");
	if (!buffer_path)
		ft_free_mem_buff(buffer, NULL, 0);
	buffer_fd = open(buffer_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (buffer_fd == -1)
		ft_free_mem_buff(buffer, buffer_path, 0);
	if (write(buffer_fd, buffer, ft_strlen(buffer)) == -1)
		ft_free_mem_buff(buffer, buffer_path, buffer_fd);
	if (close(buffer_fd) == -1)
		ft_free_mem_buff(buffer, buffer_path, 0);
	free(buffer);
	return (buffer_path);
}

char	*urand_buffer(void)
{
	char	*buffer;
	int		urand_fd;
	int		i;
	int		rd;

	urand_fd = open("dev/urandom", O_RDONLY);
	if (urand_fd == -1)
		ft_free_mem_buff(NULL, NULL, 0);
	buffer = (char *)malloc(sizeof(char) * 502);
	if (!buffer)
		ft_free_mem_buff(NULL, NULL, urand_fd);
	i = -1;
	rd = 1;
	while (++i < 500 && rd != -1)
	{
		rd = read(urand_fd, &buffer[i], 1);
		if (rd == -1)
			ft_free_mem_buff(buffer, NULL, urand_fd);
	}
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	if (close(urand_fd) == -1)
		ft_free_mem_buff(buffer, NULL, 0);
	return (buffer);
}
