/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:26:28 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/29 11:51:33 by tiaferna         ###   ########.fr       */
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

void		ft_pipex(char **argv, char **envp);
void		ft_perror_exit(char *str);

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_check_path(char* cmd, char **envp);
char		*ft_env_paths(char **envp);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_paths_environment();

int			ft_strcmp(char *str1, char *str2);
int			ft_strlen(const char *s);

#endif