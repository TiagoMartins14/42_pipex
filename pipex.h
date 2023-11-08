/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:26:28 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/08 12:46:43 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "src/libft/ft_printf/ft_printf.h"
# include "src/libft/libft.h"

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

char		*ft_check_path(char* cmd, char **envp);
char		*ft_env_paths(char **envp);
char		**ft_split_paths(char **paths);
char		*ft_strndup(const char *s, size_t n);

#endif
