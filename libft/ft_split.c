/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:53 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:16 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	**malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

static char	*put_characters_array(char *start_word, size_t len_word)
{
	char	*case_array;
	size_t	i;

	case_array = malloc(sizeof(char) * (len_word + 1));
	if (!case_array)
		return (0);
	i = 0;
	while (len_word--)
	{
		case_array[i] = start_word[i];
		i++;
	}
	case_array[i] = '\0';
	return (case_array);
}

static char	**put_words_tab(char **tab, char *str, char separator,
							size_t size_word)
{
	char			*start_array;
	size_t			i;

	i = 0;
	while (size_word--)
	{
		while (*str == separator)
			str++;
		start_array = (char *)str;
		while (*str && *str != separator)
			str++;
		tab[i] = put_characters_array(start_array, str - start_array);
		if (!tab[i++])
			return (malloc_error(tab));
	}
	tab[i] = 0;
	return (tab);
}

static size_t	count_words(char *str, char character)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == character)
			str++;
		if (!*str)
			break ;
		while (*str && *str != character)
			str++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *str, char separator)
{
	char			**tab;
	size_t			size_word;

	if (!str)
		return (0);
	size_word = count_words((char *)str, separator);
	tab = malloc(sizeof(char *) * (size_word + 1));
	if (!tab)
		return (0);
	return (put_words_tab(tab, (char *)str, separator, size_word));
}
