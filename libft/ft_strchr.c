/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:57 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/25 15:11:58 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if (character == '\0')
		return ((char *) str);
	return (0);
}
