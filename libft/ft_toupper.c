/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:13:56 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:13:57 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}