/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalidelbahry <khalidelbahry@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:57 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/05/03 16:31:01 by khalidelbah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int ft_cont_word(char *str)
{
	int i = 0, count = 0;
	
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != ' ' && str[i])
		count++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i])
			count++;
		if (str[i] == '"')
		{
			while (str[i])
			{
				i++;
				if (str[i] == '"')
					break;
			}
			i++;
		}
		if (str[i] == '\'')
		{
			while (str[i])
			{
				i++;
				if (str[i] == '\'')
					break;
			}
			i++;
		}
		while (str[i] && str[i] == ' ' && str[i] != '"' && str[i] != '\'')
			i++;
		while (str[i] != ' ' && str[i] && str[i] != '"' && str[i] != '\'')
			i++;
	}
	return(count);
}

char **split(char *str)
{
	char **line;
	
	line = malloc (ft_cont_word(str) + 1);
	 
}
