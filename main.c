/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:44:37 by rbrune        #+#    #+#                 */
/*   Updated: 2022/06/02 13:21:01 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// To search for the path inside the environment variables
char	*search_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

// To close the pipes
void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

//Closes files, free's the cmd_paths from ft_split
void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

//Pipe: One way com, one end writes the other reads

//Opens the files, makes the pipes, search for the cmd path
//saves the command paths, forks the parent into 2 children
//then children both do their command and open/close FD's

int	wait_children(t_pipex *pipex)
{
	int	status;

	status = 0;
	close_pipes(pipex);
	waitpid(pipex->pid1, &status, 0);
	waitpid(pipex->pid2, &status, 0);
	parent_free(pipex);
	return (WEXITSTATUS(status));
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;
	int		exit_status;

	if (argc != 5)
		ft_write_err("Invalid number of arguments", 127);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		ft_perror("Outfile", 1);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_perror("Infile", 1);
	if (pipe(pipex.pipe) < 0)
		ft_perror("Pipe", 1);
	pipex.paths = search_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	if (!pipex.cmd_paths)
		ft_write_err("Malloc Failed", 1);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child_1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child_2(pipex, argv, envp);
	exit_status = wait_children(&pipex);
	exit (exit_status);
}
