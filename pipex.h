/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:45:54 by rbrune        #+#    #+#                 */
/*   Updated: 2022/05/12 13:23:23 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/*to perror*/
# include <stdio.h>

/* own library */
# include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;	
	int		pipe[2];
	char	*cmd;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
}t_pipex;

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_malloc_check(void *str);
void	child_1(t_pipex pipex, char **argv, char **envp);
void	child_2(t_pipex pipex, char **argv, char **envp);
void	ft_perror(char *error, int exit_code);
void	ft_write_err(char *error, int exit_code);

#endif