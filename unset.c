/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:50:09 by yel-mens          #+#    #+#             */
/*   Updated: 2025/03/08 16:50:10 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_cmd *cmd, t_shell *shell)
{
	t_env	*unset_env;
	
	if (!cmd->args[1])
		return (EXIT_SUCCESS);
	unset_env = ft_search_env(cmd->args[1], shell);
	if (!unset_env)
		return (EXIT_SUCCESS);

}
