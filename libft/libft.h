/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:12:15 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/31 12:53:14 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** LIBFT FONCTIONS
*/

int		get_next_line(char **line);
void	*ft_memcpy(void *dest, const void *src, size_t size_tocopy);
void	ft_putstr_fd(char *str, int fd, char newline);
char	**ft_split(char const *str, char separator);
char	*ft_strdup(const char *src_tocopy);
char	*ft_strjoin(char const *str1, char const *str2, int free_1);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *inside, const char *tofind,
			size_t len_tosearch);
void	print_table(char *message, int **int_tab, size_t size, char **str_tab);
void	print_array(char *message, int *ar_int, size_t size, char *string);

#endif
