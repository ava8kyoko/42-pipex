/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:12:02 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/25 15:12:03 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* 
** I free only str1, because str2 isn't a malloc and 
** str1 will contain strjoin return.
*/

char	*ft_strjoin(char const *str1, char const *str2, int free_1)
{
	char	*memory_space;
	size_t	len_str1;
	size_t	len_str2;

	if (!str1 || !str2)
		return (0);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	memory_space = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!memory_space)
		return (0);
	ft_memcpy(memory_space, str1, len_str1);
	if (free_1)
		free((char *)str1);
	ft_memcpy((memory_space + len_str1), str2, (len_str2 + 1));
	return (memory_space);
}
