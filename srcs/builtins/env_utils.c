/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:00:01 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/09 17:28:12 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//returns the value "/home/directory"
char	*ft_get_val(char *var, t_shell *shell)
{
	t_env	*env;
	char	*sep;

	env = ft_search_env(var, shell);
	if (!env || !env->data)
		return (NULL);
	sep = ft_strchr(env->data, '=');
	if (!sep || !*(sep + 1))
		return (NULL);
	sep = ft_strdup(sep + 1);
	return (sep);
}

static char	*build_new_env(char *var, char *data)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(var, "=");
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, data);
	free(tmp);
	return (result);
}

char	*ft_update_env(char *var, char *data, t_shell *shell) // update value
{
	t_env	*env;
	char	*new_data;

	env = ft_search_env(var, shell);
	if (!env)
	{
		new_data = build_new_env(var, data);
		if (!new_data)
			return (NULL);
		ft_append_env(new_data, shell);
		return (new_data);
	}
	free(env->data);
	new_data = build_new_env(var, data);
	if (!new_data)
		return (NULL);
	env->data = new_data;
	return (env->data);
}
