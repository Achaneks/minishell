/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-bahr <kel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:57 by kel-bahr          #+#    #+#             */
/*   Updated: 2025/04/30 14:39:26 by kel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

// int ft_cont_word(char *str)
// {
// 	int i;
// 	int count;
// 	int flag;
// 	int f2;

// 	f2 = 0;
// 	flag = 0;
// 	i = 0;
// 	count = 0;
// 	while(str[i])
// 	{
// 		if (str[i] == '"' && flag == 0)
// 			flag = 1;
// 		else if (str[i] == '"' && flag == 1)
// 			flag = 0;
// 		if (str[i] == '\'' && f2 == 0)
// 			f2 = 1;
// 		else if (str[i] == '\'' && f2 == 1)
// 			f2 = 0;
// 		if(str[i] == ' ')
// 		{
// 			if (!flag || !f2)
// 				count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

int ft_cont_word(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
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
		}
		if (str[i] == '\'')
		{
			while (str[i])
			{
				i++;
				if (str[i] == '\'')
					break;
			}
		}
		if (str[i] == ' ')
		{
			count++;
			while (str[i] && str[i] == ' ')
				i++;
		}
		while (str[i] != ' ' && str[i])
			i++;
	}
	return(count);
}

// char **split(char *str)
// {
// 	char **line;

// }
