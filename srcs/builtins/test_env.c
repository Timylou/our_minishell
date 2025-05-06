/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:42 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/05 17:48:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// t_env	*create_env_list(char **envp)
// {
// 	t_env	*head = NULL;
// 	t_env	*last = NULL;
// 	t_env	*node;
// 	int		i = 0;

// 	while (envp[i])
// 	{
// 		node = malloc(sizeof(t_env));
// 		if (!node)
// 			return (NULL);
// 		node->data = ft_strdup(envp[i]);
// 		node->next = NULL;
// 		node->prev = last;
// 		if (last)
// 			last->next = node;
// 		else
// 			head = node;
// 		last = node;
// 		i++;
// 	}
// 	return (head);
// }

// int	main(int ac, char **av, char **envp)
// {
// 	t_env *tmp= NULL;
// 	t_env *envlist = create_env_list(envp);
// 	(void)ac;
// 	(void)av;
// 	ft_env_builtins(NULL, envlist);
// 	while (envlist)
// 	{
// 		tmp = envlist->next;
// 		free(envlist->data);
// 		free(envlist);
// 		envlist = tmp;
// 	}
// 	return (0);
// }
