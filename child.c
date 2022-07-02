/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 12:31:25 by rbrune        #+#    #+#                 */
/*   Updated: 2022/05/12 13:20:51 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//in the path, strjoins until we get the full command
static char	*get_command(char **paths, char *cmd)
{
	char	*full_command;
	char	*tmp;

	if (!cmd)
		return (NULL);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		if (!tmp)
			ft_write_err("Malloc Failed", 1);
		full_command = ft_strjoin(tmp, cmd);
		if (!full_command)
			ft_write_err("Malloc Failed", 1);
		free(tmp);
		if (access(full_command, X_OK) == 0)
		{
			return (full_command);
		}
		free(full_command);
		paths++;
	}
	return (NULL);
}

void	child_1(t_pipex pipex, char **argv, char **envp)
{	
	int	i;

	i = 0;
	dup2(pipex.infile, 0);
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	pipex.cmd_args = ft_split(argv[2], ' ');
	if (!pipex.cmd_args)
		ft_write_err("Malloc Failed", 1);
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (pipex.cmd == NULL)
	{
		while (pipex.cmd_args[i])
		{
			free(pipex.cmd_args[i]);
			i++;
		}
		free(pipex.cmd_args);
		free(pipex.cmd);
		ft_write_err("Command not found\n", 127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	child_2(t_pipex pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	dup2(pipex.outfile, 1);
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	pipex.cmd_args = ft_split(argv[3], ' ');
	if (!pipex.cmd_args)
		ft_write_err("Malloc Failed", 1);
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		while (pipex.cmd_args[i])
		{
			free(pipex.cmd_args[i]);
			i++;
		}
		free(pipex.cmd_args);
		free(pipex.cmd);
		ft_write_err("Command not found\n", 127);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
