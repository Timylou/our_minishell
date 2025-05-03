/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:45:12 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/03 10:34:17 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

static void	ft_free_cmds(t_cmd *cmds)
{
	t_cmd	*next_cmd;

	next_cmd = NULL;
	while (cmds)
	{
		next_cmd = cmds->next;
		ft_free_array(cmds->args);
		close(cmds->in);
		close(cmds->out);
		free(cmds);
		cmds = next_cmd;
	}
}

void	ft_free_env(t_env *env)
{
	t_env	*next_env;

	next_env = NULL;
	while (env)
	{
		next_env = env->next;
		free(env->data);
		free(env);
		env = next_env;
	}
}

void	ft_error(char *msg, t_shell *shell)
{
	if (!shell)
		exit(EXIT_FAILURE);
	perror(msg);
	ft_free_shell(shell);
}

void	ft_free_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->cmds)
			ft_free_cmds(shell->cmds);
		if (shell->env)
			ft_free_env(shell->env);
		free(shell);
	}
}
