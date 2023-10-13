/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:26:28 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/12 22:44:15 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

# define READ_END	0
# define WRITE_END	1

void		ft_pipex(char **argv);

char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_strcmp(char *str1, char *str2);
int			ft_strlen(const char *s);

// static int	elements(char const *s, char c);
// static int	size_of_word(char const *s, char c, int i);

#endif