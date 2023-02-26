/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:48:10 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/31 12:53:04 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd, char newline)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
	if (newline == 'n')
		write(fd, "\n", 1);
}
