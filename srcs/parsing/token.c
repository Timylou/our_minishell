/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:18:43 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/04 16:59:56 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_next_word(char *line, int *i)
{
	int		begin_word;
	int		end_word;
	int		j;
	char	*word;

	while (line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n'
		|| line[*i] == '\v' || line[*i] == '\f' || line[*i] == '\r')
			*i += 1;
	begin_word = *i;
	while (line[*i]
		&& !(line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n'
		|| line[*i] == '\v' || line[*i] == '\f' || line[*i] == '\r'))
			*i += 1;
	end_word = (*i)++;
	word = malloc(sizeof(char) * (end_word - begin_word) + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < end_word - begin_word)
	{
		word[j] = line[begin_word + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

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
	token->value = ft_get_next_word(line, i);
	if (!token->value)
	{
		free(token);
		ft_error("token value malloc error", EXIT_MALLOC, shl);
	}
	return (token);
}

static void	ft_switch_token(char *line, int *i, t_token **token, t_shell *shell)
{
	t_token	*aux_token;
	t_token	*cur_token;

	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		*i += 1;
		cur_token = ft_add_token(line, i, TOKEN_HEREDOC, shell);
	}
	else if (line[*i] == '<')
		cur_token = ft_add_token(line, i, TOKEN_REDIR_IN, shell);
	else if (line[*i] == '>')
		cur_token = ft_add_token(line, i, TOKEN_REDIR_OUT, shell);
	else
		cur_token = ft_add_token(line, i, TOKEN_WORD, shell);
	if (*token)
	{
		aux_token = *token;
		while (aux_token->next)
			aux_token = aux_token->next;
		aux_token->next = cur_token;
	}
	else
		*token = cur_token;
}

t_token	*ft_tokeniser(char *line, t_shell *shell)
{
	t_token	*token;
	int		i;

	token = NULL;
	i = 0;
	while (line[i])
		ft_switch_token(line, &i, &token, shell);
	return (token);
}
