/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:18:05 by achanek           #+#    #+#             */
/*   Updated: 2025/05/05 11:30:55 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	get_token_type(char *s)
{
	if (ft_strcmp(s, "|") == 0)
		return (TOKEN_PIPE);
	if (ft_strcmp(s, ">") == 0)
		return (TOKEN_REDIR_OUT);
	if (ft_strcmp(s, "<") == 0)
		return (TOKEN_REDIR_IN);
	if (ft_strcmp(s, ">>") == 0)
		return (TOKEN_REDIR_APPEND);
	if (ft_strcmp(s, "<<") == 0)
		return (TOKEN_HEREDOC);
	if (s[0] == '$' && s[1])
		return (TOKEN_VAR);
	return (TOKEN_WORD);
}

t_token	*tokenize(char **line)
{
	t_token *tokens;
	int i;
	int type;

	tokens = NULL;
	i = 0;
	while (line[i])
	{
		type = get_token_type(line[i]);
		add_back_token(&tokens,new_token(line[i],type));
		i++;
	}
	return (tokens);
}