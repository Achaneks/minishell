/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanek <achanek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:36:53 by achanek           #+#    #+#             */
/*   Updated: 2025/04/30 11:51:39 by achanek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;

	char *input;

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
		printf("You typed: %s\n", input);
		free(input);
	}
	return 0;
}
