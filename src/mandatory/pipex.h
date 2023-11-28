/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:37:57 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/27 23:50:36 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"

# define READ_END	0
# define WRITE_END	1
# define IN_FILE	0
# define OUT_FILE	1
# define COMMAND_NOT_FOUND 127

/* checkers.c */
char	*check_path(char *cmd, char **path_array);
char	*ft_check_infile(char *argv);
char	*ft_urandom_infile(void);
char	*urand_buffer(void);
void	command_check(char *arg);

/* execute.c */
void	execute_in(char **argv, char **path_array, char **envp);
void	execute_out(char **argv, char **path_array, char **envp);

/* memory_frees.c */
void	ft_free_array(char **array);
void	free_array_and_exit(char **array, char *error);
void	ft_perror_exit(char *str, int error);
void	free_mem_buff(char *buffer, char *path, int fd);

/* split_paths.c */
char	**create_path_array(char **env);


#endif