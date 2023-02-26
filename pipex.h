/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:13:25 by mchampag          #+#    #+#             */
/*   Updated: 2022/10/31 12:04:33 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open
# include "./libft/libft.h"
# include <stdio.h> // printf
# include <stdlib.h>  // malloc free exit
# include <string.h>
# include <sys/wait.h> // wait waitpid
# include <unistd.h> // Access close read write dup dup2 execve fork pipe unlink

/*
** PIPEX FONCTIONS
*/

int		main(int argc, char **argv, char **envp);

/*
** EXECUTE FONCTIONS
*/

void	execute(char *command, char **envp);

/*
** UTILS FONCTIONS
*/

void	free_table(char *str, char **tab);
int		check_error(int return_value, char *message);

#endif
