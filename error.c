/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/20 12:50:24 by rbrune        #+#    #+#                 */
/*   Updated: 2022/05/05 17:20:02 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *error, int exit_code)
{
	perror(error);
	exit (exit_code);
}

void	ft_write_err(char *error, int exit_code)
{
	write(2, error, ft_strlen(error));
	exit (exit_code);
}
