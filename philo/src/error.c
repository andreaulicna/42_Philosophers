/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:54:45 by aulicna           #+#    #+#             */
/*   Updated: 2023/12/27 14:52:47 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incl/philosophers.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
	{
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	error(int error)
{
	if (error == 2)
		ft_putstr_fd("Error: Encountered memory allocation error.\n", 2);
	return (error);
}
