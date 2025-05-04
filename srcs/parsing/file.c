/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:15:55 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/03 23:30:50 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_infile(char *filename, t_cmd *cmd)
{
	cmd->in = open(filename, O_RDONLY);
	if (cmd->in < 0)
		perror(filename);
}

void	ft_open_outfile(char *filename, t_cmd *cmd, t_token_type type)
{
	if (type == TOKEN_REDIR_OUT)
		cmd->out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		cmd->out = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->out < 0)
		perror(filename);
}