/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:39:57 by yel-mens          #+#    #+#             */
/*   Updated: 2025/03/05 08:52:17 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_dup_files(t_cmd *cmd, t_shell *shell)
{
	if (dup2(cmd->in, STDIN_FILENO) < 0)
		ft_error(cmd->args[0], shell);
	if (dup2(cmd->out, STDOUT_FILENO) < 0)
		ft_error(cmd->args[1], shell);
}

static void ft_built_in(t_cmd *cmd, t_shell *shell)
{
	if (!ft_strcmp(cmd->args[0], "cd"))
		ft_cd(cmd, shell);
	else if (!ft_strcmp(cmd->args[0], "echo"))
		ft_echo(cmd, shell);
	else if (!ft_strcmp(cmd->args[0], "env"))
		ft_env(cmd, shell);
	else if (!ft_strcmp(cmd->args[0], "exit"))
		ft_exit(cmd, shell);
	else if (!ft_strcmp(cmd->args[0], "export"))
		ft_export(cmd, shell);
	else if (!ft_strcmp(cmd->args[0], "pwd"))
		ft_pwd(cmd, shell);
	else if (!ft_strcmp(cmd->args[0], "unset"))
		ft_unset(cmd, shell);
}

void	ft_exec(t_shell *shell)
{
	pid_t	pid;
	t_cmd	*all_cmd;

	all_cmd = shell->cmds;
	while (all_cmd)
	{
		pid = fork();
		if (pid < 0)
			ft_error("fork failed", shell);
		if (!pid)
		{
			ft_dup_files(all_cmd, shell);
			ft_close(shell->cmds);
			ft_built_in(all_cmd, shell);
			if (execve(all_cmd->args[0], call_cmd->args, shell->env) < 0)
				ft_error("execve failed", shell);
		}
		all_cmd = all_cmd->next;
	}
	ft_close(shell->cmds);
}
