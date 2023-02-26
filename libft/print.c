/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:46 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/25 16:05:55 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// try -> void	print_table(char *type, void **tab)
void	print_table(char *message, int **int_tab, size_t size, char **str_tab)
{
	int	i;

	if (message)
		printf("%s\n", message);
	if (size)
	{
		while (size--)
		{
			i = 0;
			while (*int_tab[i])
				printf("%d ", *int_tab[i]);
			printf("\n");
			int_tab++;
		}
	}
	else
	{
		while (*str_tab)
		{
			printf("%s\n", *str_tab);
			str_tab++;
		}
	}
}

void	print_array(char *message, int *ar_int, size_t size, char *string)
{
	if (message)
		printf("%s\n", message);
	if (size)
	{
		while (size--)
		{
			printf(" %d\n", *ar_int);
			ar_int++;
		}	
	}
	else
	{
		while (*string)
		{
			printf(" %c\n", *string);
			string++;
		}
	}
}
