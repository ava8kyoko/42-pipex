/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:12:09 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/26 13:06:10 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *inside, const char *tofind,
			size_t len_tosearch)
{
	size_t	start;
	size_t	i;

	start = 0;
	if (!tofind)
		return ((char *) inside);
	if (inside)
	{
		while (inside[start] != '\0' && start < len_tosearch)
		{
			i = 0;
			while (inside[start + i] == tofind[i] && start + i < len_tosearch)
				if (tofind[i++ + 1] == 0)
					return ((char *)&inside[start]);
			start++;
		}
	}
	return (0);
}
