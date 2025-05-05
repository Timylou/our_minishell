/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:47:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/05 17:38:30 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*ft_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->in = STDIN_FILENO;
	cmd->out = STDOUT_FILENO;
	cmd->read_out = -1;
	cmd->next = NULL;
	return (cmd);
}

static int	ft_manage_token(t_token **token, t_cmd *cmd, t_shell *shell)
{
	int	success;

	success = 1;
	if ((*token)->type == TOKEN_REDIR_IN)
		success = ft_open_infile((*token)->value, cmd);
	else if ((*token)->type == TOKEN_REDIR_OUT
		|| (*token)->type == TOKEN_REDIR_APPEND)
		success = ft_open_outfile((*token)->value, cmd, (*token)->type);
	else if ((*token)->type == TOKEN_WORD)
		success = ft_open_cmd(token, cmd, shell);
	return (success);
}

static void	ft_free_token(t_token *token)
{
	t_token	*next_token;

	while (token)
	{
		next_token = token->next;
		free(token->value);
		free(token);
		token = next_token;
	}
}

void	ft_parse(char *line, t_shell *shell)
{
	t_token	*token;
	t_token	*all_token;
	t_cmd	*cmd;

	all_token = ft_tokeniser(line, shell);
	token = ft_sort_token(all_token);
	all_token = token;
	cmd = ft_init_cmd();
	if (!cmd)
		ft_error("cmd malloc error", EXIT_MALLOC, shell);
	while (token)
	{
		if (!ft_manage_token(&token, cmd, shell))
			break ;
		if (token)
			token = token->next;
	}
	ft_free_token(all_token);
	shell->cmds = cmd;
}
