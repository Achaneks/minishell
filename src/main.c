/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:36:53 by achanek           #+#    #+#             */
/*   Updated: 2025/05/04 11:53:52 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;

	char *input;
	char **str;
	int i = 0;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("exit\n");
			break;
		}
		if (*input)
			add_history(input);
		if (!check_couts(input))
		{
			str  = split(input);
			while(str[i])
			{
				printf("%s\n", str[i]);
				i++;
			}
		}
		free(input);
		i = 0;
	}
	return 0;
}
