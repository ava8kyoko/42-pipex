/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:12:00 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/25 16:02:54 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *src_tocopy)
{
	char	*memory_space;
	size_t	i;
	size_t	len;

	len = ft_strlen(src_tocopy);
	memory_space = malloc(sizeof(char) * len + 1);
	if (!memory_space)
		return (0);
	i = 0;
	while (src_tocopy[i] != '\0' && len--)
	{
		memory_space[i] = src_tocopy[i];
		i++;
	}
	memory_space[i] = '\0';
	return (memory_space);
}
