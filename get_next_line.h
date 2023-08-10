/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:20:13 by Verdant           #+#    #+#             */
/*   Updated: 2023/01/17 16:27:47 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> // delete this when finished
# include <stdio.h> // delete this when finished
# include <string.h> // delete this when finished

/*			UTILS			*/
int		ft_strlen(char *str);
int		search_char(char *buffer, char c);
int		ft_strclen(char *s, char c);

/*			Main			*/
void	modify_buffer(char *buffer);
char	*clear_buffer(char *buffer);
char	*read_file(char *buffer, char *line, int fd);
char	*get_next_line(int fd);

#endif
