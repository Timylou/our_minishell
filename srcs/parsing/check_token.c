/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:35:28 by yel-mens          #+#    #+#             */
/*   Updated: 2025/06/29 09:35:28 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_wrong_token(t_token *token, int is_cmd)
{
	return (((token->type != TOKEN_WORD && token->type != TOKEN_PIPE)
			&& (!token->value || !token->value[0]))
		|| (token->type == TOKEN_PIPE && is_cmd == 0));
}

static t_token	*ft_free_null_token(t_token *token, t_token **all_token)
{
	t_token	*temp;

	if (*all_token == token)
	{
		*all_token = (*all_token)->next;
		if (token->value)
			free(token->value);
		free(token);
		return (*all_token);
	}
	temp = *all_token;
	while (temp->next != token)
		temp = temp->next;
	temp->next = token->next;
	if (token->value)
		free(token->value);
	free(token);
	token = NULL;
	return (temp);
}

int	ft_check_token(t_token **all_token)
{
	t_token	*token;
	int		is_cmd;

	token = *all_token;
	is_cmd = 0;
	while (token)
	{
		if (token->type != TOKEN_PIPE)
			is_cmd = 1;
		if (ft_check_wrong_token(token, is_cmd))
		{
			ft_free_token(*all_token);
			return (0);
		}
		if (token->type == TOKEN_PIPE)
			is_cmd = 0;
		if ((!token->value || !token->value[0]) && token->type == TOKEN_WORD)
			token = ft_free_null_token(token, all_token);
		if (token)
			token = token->next;
	}
	if (!is_cmd)
		ft_free_token(*all_token);
	return (is_cmd);
}
