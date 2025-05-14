/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:27:43 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/14 17:36:32 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_error_msj(char *arg, char *msj)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msj)
		ft_putendl_fd(msj, STDERR_FILENO);
}
int	ft_parsing_export_arg(char *arg)
{
	int	i;

	i = 1;
	if (!ft_isalpha(arg[0]) && (arg[0] != '_'))
		return (1);
	while (arg[i] && !(arg[i] == '=' || (arg[i] \
== '+' && arg[i + 1] == '=')))
	{
		if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]) \
&& !(arg[i] == '_'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_equal(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		else if (arg[i] == '+' && arg[i + 1] == '=')
			return (2);
		i++;
	}
	return (0);
}

int	ft_var_exists(t_shell *shell)
{
	char	*arg;
	t_env	*env;

	arg = shell->cmds->args[1];
	env = shell->env;
	while (env)
	{
		if (ft_compare_nom(env->data, arg) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}
