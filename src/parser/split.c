/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:32:36 by achanek           #+#    #+#             */
/*   Updated: 2025/05/04 11:39:16 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int ft_cont_word(char *str)
{
	int i = 0, count = 0;

	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] != ' ' && str[i])
		count++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] && str[i] != '"' && str[i] != '\'')
			i++;
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
		if (str[i] != ' ' && str[i - 1] == ' ' &&str[i])
			count++;
	}
	return(count);
}

static void	str_free(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*p;

	i = ft_strlen(s);
	p = (char *)malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	find_next_substr(const char *s, int *start, int *end)
{
	while (s[*start] == ' ')
		(*start)++;
	*end = *start;
	while(s[*end] != ' ' && s[*end])
	{
		while (s[*end] && s[*end] != ' ' &&  s[*end] != '"' && s[*end] != '\'')
			(*end)++;
		if (s[*end] == '"')
		{
			while (s[*end])
			{
				(*end)++;
				if (s[*end] == '"')
					break;
			}
			(*end)++;
		}
		if (s[*end] == '\'')
		{
			while (s[*end])
			{
				(*end)++;
				if (s[*end] == '\'')
				break;
			}
			(*end)++;
		}
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[len] = '\0';
	return (sub);
}

char **split(char *str)
{
	char **line;
	int i;
	int start;
	int end;

	line = malloc ((ft_cont_word(str) + 1) * sizeof(char *));
	i = 0;
	start = 0;
	end = 0;
	while (str[start])
	{
		find_next_substr(str, &start, &end);
		if (start == end)
			break;
		line[i] = ft_substr(str, start, end - start);
		if (!line[i])
			return(str_free(line, i), NULL);
		i++;
		start = end;
	}
	line [i] = NULL;
	return(line);
}