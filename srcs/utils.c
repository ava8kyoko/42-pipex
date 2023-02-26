/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:29 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/31 13:01:29 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_table(char *str, char **tab)
{
	size_t	i;

	if (str)
		free(str);
	else if (tab)
	{
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

int	check_error(int return_value, char *message)
{
	if (return_value == -1)
	{
		ft_putstr_fd(message, 2, 'n');
		exit(EXIT_FAILURE);
	}
	return (return_value);
}
