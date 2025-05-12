/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:17:11 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/12 14:53:06 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int	ft_printf_export(t_env *env)
{
	t_env	*env_copy;
	t_env	*tmp;


	env_copy = ft_cread_env_copy(env);
	if (!env_copy)
		return (1);
	ft_sort_env_copy(env_copy);
	tmp = env_copy;
	while (env_copy)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putendl_fd(env_copy->data, STDOUT_FILENO);
		env_copy = env_copy->next;
	}
	ft_free_env(tmp);
	return (0);
}

int	ft_export_builtins(t_shell *shell)
{
	if (!shell->cmds->args[1])
		ft_printf_export(shell->env);
	return (0);
}

