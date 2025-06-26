/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:18:43 by yel-mens          #+#    #+#             */
/*   Updated: 2025/06/26 14:52:57 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*ft_add_token(char *line, int *i, t_token_type t, t_shell *shl)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		ft_error("token malloc error", EXIT_MALLOC, shl);
	token->type = t;
	if (token->type == TOKEN_REDIR_IN || token->type == TOKEN_REDIR_OUT)
		*i += 1;
	if (token->type == TOKEN_HEREDOC || token->type == TOKEN_REDIR_APPEND)
		*i += 2;
	token->next = NULL;
	token->value = ft_get_next_word(line, i, shl);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	if (!token->value[0] && token->type != TOKEN_WORD)
	{
		free(token->value);
		free(token);
		return (NULL);
	}
	return (token);
}

static t_token	*ft_add_token_pipe(int *i, t_shell *shell)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		ft_error("token malloc error", EXIT_MALLOC, shell);
	token->type = TOKEN_PIPE;
	token->next = NULL;
	token->value = NULL;
	*i += 1;
	return (token);
}

static t_token	*ft_swtch_tkn(char *line, int *i, t_token **tkn, t_shell *shl)
{
	t_token	*aux_token;
	t_token	*cur_token;

	if (line[*i] == '<' && line[*i + 1] == '<')
		cur_token = ft_add_token(line, i, TOKEN_HEREDOC, shl);
	else if (line[*i] == '<')
		cur_token = ft_add_token(line, i, TOKEN_REDIR_IN, shl);
	else if (line[*i] == '>' && line[*i + 1] == '>')
		cur_token = ft_add_token(line, i, TOKEN_REDIR_APPEND, shl);
	else if (line[*i] == '>')
		cur_token = ft_add_token(line, i, TOKEN_REDIR_OUT, shl);
	else if (line[*i] == '|')
		cur_token = ft_add_token_pipe(i, shl);
	else
		cur_token = ft_add_token(line, i, TOKEN_WORD, shl);
	if (*tkn)
	{
		aux_token = *tkn;
		while (aux_token->next)
			aux_token = aux_token->next;
		aux_token->next = cur_token;
	}
	else
		*tkn = cur_token;
	return (cur_token);
}

t_token	*ft_tokeniser(char *line, t_shell *shell)
{
	t_token	*token;
	int		len;
	int		i;

	token = NULL;
	len = ft_strlen(line);
	i = 0;
	while (i < len && ft_isspace(line[i]))
		i++;
	while (i < len)
	{
		if (!ft_swtch_tkn(line, &i, &token, shell))
		{
			ft_free_token(token);
			return (NULL);
		}
		while (i < len && ft_isspace(line[i]))
			i++;
	}
	return (token);
}
