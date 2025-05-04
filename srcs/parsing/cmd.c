/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:56:04 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/04 12:41:52 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	nb_word(t_token *token)
{
	int	i;

	i = 0;
	while (token && token->type == TOKEN_WORD)
	{
		token = token->next;
		i++;
	}
	return (i);
}

int	ft_open_cmd(t_token	**token, t_cmd *cmd)
{
	int		nb_args;
	int		i;
	int		success;
	char	**args;

	nb_args = nb_word(*token);
	args = malloc(sizeof(char *) * (nb_args + 1));
	if (!args)
		return (0);
	success = 1;
	i = 0;
	while (i < nb_args)
	{
		args[i] = ft_strdup((*token)->value);
		if (!args[i])
			success = 0;
		i++;
		*token = (*token)->next;
	}
	args[i] = NULL;
	cmd->args = args;
	return (success);
}
