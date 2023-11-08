/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:26:28 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/03 10:04:38 by patatoss         ###   ########.fr       */
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
# include "libft/libft.h"

# define READ_END	0
# define WRITE_END	1
# define IN_FILE	0
# define OUT_FILE	1
# define COMMAND_NOT_FOUND 127

void		ft_pipex(char **argv, char **envp, char **cmd1, char **cmd2);
void		ft_perror_exit(char *str, int error);
void		ft_free_tab(char **tab);
void		ft_free_all_tabs(char **tab1, char **tab2);
void		ft_execute_in(char **argv, char *path1, char **cmd1, int *fd_pipe);
void		ft_execute_out(char **argv, char *path2, char **cmd2, int *fd_pipe);
void		ft_free_mem_buff(char *buffer, char *path, int fd);

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_check_path(char* cmd, char **envp);
char		*ft_env_paths(char **envp);
char		**ft_split(char const *s, char c);
char		**ft_split_paths(char **paths);
char		*ft_strndup(const char *s, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_strcmp(char *str1, char *str2);
int			ft_strlen(const char *s);

#endif