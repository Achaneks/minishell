/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_couts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:20:42 by achanek           #+#    #+#             */
/*   Updated: 2025/05/04 11:54:24 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"



int check_couts(char *str)
{
	int i = 0;
	int single_quote = 0;
	int double_quote = 0;

	while (str[i])
	{
		if (str[i] == '\'' && !single_quote && !double_quote)
		{
			single_quote = !single_quote;
			i++;
			continue ;
		}
		if (str[i] == '\'' && single_quote)
		{
			single_quote = !single_quote;
			i++;
			continue ;
		}
		if (str[i] == '"' && !double_quote && !single_quote)
		{
			double_quote = !double_quote;
			i++;
			continue ;
		}
		if (str[i] == '"' && double_quote)
		{
			double_quote = !double_quote;
			i++;
			continue ;
		}
		if (single_quote || double_quote)
		{
			i++;
			continue;
		}
		i++;
	}
	if (single_quote || double_quote)
		return ((printf("error invalid input\n")), 1);
	return (0);
}
