/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:21:39 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/04 12:46:08 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dup_files(t_cmd *cmd)
{
	if (cmd->in >= 0)
	{
		if (dup2(cmd->in, STDIN_FILENO) < 0)
		{
			perror("dup2 to stdin");
			close(cmd->in);
			close(cmd->out);
			return (0);
		}
		close(cmd->in);
	}
	if (cmd->out >= 0)
	{
		if (dup2(cmd->out, STDOUT_FILENO) < 0)
		{
			perror("dup2 to stdout");
			close(cmd->out);
			return (0);
		}
		close(cmd->out);
	}
	return (1);
}

static int	ft_exec(t_cmd *cmd, char **env)
{
	if (!cmd->args)
		return (0);
	if (execve(cmd->args[0], cmd->args, env) < 0)
		return (0);
	return (1);
}

static void	ft_close(t_cmd *all_cmd, t_cmd *cmd)
{
	while (all_cmd)
	{
		if (all_cmd != cmd)
		{
			if (all_cmd->in >= 0)
				close(all_cmd->in);
			if (all_cmd->out >= 0)
				close(all_cmd->out);
		}
		all_cmd = all_cmd->next;
	}
}

void	ft_process(char **env, t_shell *shell)
{
	pid_t	pid;
	t_cmd	*cmd;

	cmd = shell->cmds;
	while (cmd)
	{
		pid = fork();
		if (pid < 0)
			return ;
		if (!pid)
		{
			ft_close(shell->cmds, cmd);
			if (!ft_dup_files(cmd))
			{
				perror(cmd->args[0]);
				ft_free_shell(shell);
				return ;
			}
			if (!ft_exec(cmd, env))
			{
				perror(cmd->args[0]);
				ft_free_shell(shell);
				exit(EXIT_FAILURE);
			}
		}
		cmd = cmd->next;
	}
}
