/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:17:43 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/17 14:18:28 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strclen(char *s, char c)
{
	int	i;
	
	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}
int	search_char(char *buffer, char c)
{
	int i;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}
int	ft_strlen(char *str)
{
	int x;
	x = 0;
	if (str == NULL)
		return (x);
	while (str[x])
		x++;
	return (x);
}