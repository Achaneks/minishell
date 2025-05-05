/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:25:29 by achanek           #+#    #+#             */
/*   Updated: 2025/05/05 10:45:57 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_token	*new_token(char *value, int type)
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = ft_strdup(value);
	new->type = type;
	new->next = NULL;
	return (new);
}

void add_back_token(t_token **list,t_token *token)
{
	t_token *temp;

	temp = *list;
	if ((*list) == NULL)
	{
		*list = token;
		return ;
	}
	while ((*list)->next)
		(*list)= (*list)->next;
	(*list)->next = token;
	(*list) = temp;
}