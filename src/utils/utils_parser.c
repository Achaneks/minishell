/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:30:47 by achanek           #+#    #+#             */
/*   Updated: 2025/05/05 11:25:01 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	r;

	r = ft_strlen(s);
	p = (char *)malloc((r + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	r = 0;
	while (s[r])
	{
		p[r] = s[r];
		r++;
	}
	p[r] = '\0';
	return (p);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}