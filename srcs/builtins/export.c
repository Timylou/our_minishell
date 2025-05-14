/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:17:11 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/14 17:37:01 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_valor(t_env *tmp)
{
	int	i;

	i = 0;
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	while (tmp->data[i] && tmp->data[i] != '=')
	{
		write (1, &tmp->data[i], 1);
		i++;
	}
	if (tmp->data[i] == '=')
	{
		i++;
		ft_putstr_fd("=\"", STDOUT_FILENO);
		while (tmp->data[i])
		{
			write (1, &tmp->data[i], 1);
			i++;
		}
		ft_putendl_fd("\"", STDOUT_FILENO);
	}
}

static int	ft_printf_export(t_env *env)
{
	t_env	*env_copy;
	t_env	*tmp;

	env_copy = ft_cread_env_copy(env);
	if (!env_copy)
		return (1);
	ft_sort_env_copy(env_copy);
	tmp = env_copy;
	while (tmp)
	{
		ft_print_valor(tmp);
		tmp = tmp->next;
	}
	ft_free_env(env_copy);
	return (0);
}



int	ft_export_builtins(t_shell *shell)
{
	int	equal;

	if (!shell->cmds->args[1])
		ft_printf_export(shell->env);
	if (shell->cmds->args[1])
	{
		if (ft_parsing_export_arg(shell->cmds->args[1]))
		{
			ft_export_error_msj(shell->cmds->args[1], \
"not a valid identifier");
			return (1);
		}
		equal = ft_check_equal(shell->cmds->args[1]);
		if (ft_var_exists(shell))
		{
			ft_printf("exist\n");
		}
	}
	/*si args[1] y si la variable existe y el argumento tiene =
	entonces tengo que actualizar el valor de la variable
	y si no existe entonces tengo que crearla y marcarla como exportada*/
	return (0);
}
