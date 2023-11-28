/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:51:48 by tiaferna          #+#    #+#             */
/*   Updated: 2023/11/27 23:55:20 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define READ_END	0
# define WRITE_END	1
# define IN_FILE	0
# define OUT_FILE	1
# define COMMAND_NOT_FOUND 127

/* checkers_bonus.c */
char	*check_path(char *cmd, char **path_array);
char	*ft_check_infile(char *argv);
char	*ft_urandom_infile(void);
char	*urand_buffer(void);
void	command_check(int argc, char **argv);

/* execute_bonus.c */
void	execute_in(char **argv, char **path_array, char **envp, int index);
void	execute_out(char **argv, char **path_array, char **envp, int i);

/* here_doc_bonus.c */
void	open_here_doc(char *here_doc);
void	get_input(char *limiter);

/* limiter_bonus.c */
char	*check_limiter(char *str, char* argv);
int		create_here_doc(char **argv);

/* memory_frees_bonus.c */
void	ft_free_array(char **array);
void	free_array_and_exit(char **array, char *error);
void	ft_perror_exit(char *str, int error);
void	free_mem_buff(char *buffer, char *path, int fd);
void	unlink_and_free(char *infile);

/* split_paths_bonus.c */
char	**create_path_array(char **env);

#endif
