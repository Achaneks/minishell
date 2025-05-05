/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:30:26 by achanek           #+#    #+#             */
/*   Updated: 2025/05/05 11:25:12 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#define	TOKEN_WORD			0
#define TOKEN_CMD			1
#define TOKEN_ARG			2
#define TOKEN_PIPE			3
#define TOKEN_REDIR_IN		4
#define TOKEN_REDIR_OUT		5
#define TOKEN_REDIR_APPEND	6
#define TOKEN_HEREDOC		7
#define TOKEN_FILE			8
#define TOKEN_VAR			9


typedef struct s_token {
	char	*value;
	int		type;
	struct s_token *next;
} t_token;


int		check_couts(char *str);
char	**split(char *str);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);


#endif
