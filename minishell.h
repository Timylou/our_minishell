/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:35:27 by yel-mens          #+#    #+#             */
/*   Updated: 2025/03/07 16:19:04 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char			**args;
	int				in;
	int				out;
	int				read_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*var;
	struct s_env	next;
}	t_env;

typedef struct s_shell
{
	t_cmd	*cmds;
	t_env	*env;
	int		exit_status;
}	t_shell;

/* * * * * *
 *  error *
 * * * * * */
void	ft_close(t_cmd *cmds);
void	ft_error(char *msg, t_shell *shell);

/* * * * * *
 *  utils *
 * * * * * */
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *str);

/* * * * * * *
 * built in *
 * * * * * * */
void	ft_cd(t_cmd *cmd, t_shell *shell);
void	ft_echo(t_cmd *cmd, t_shell *shell);
void	ft_env(t_cmd *cmd, t_shell *shell);
void	ft_exit(t_cmd *cmd, t_shell *shell);
void	ft_export(t_cmd *cmd, t_shell *shell);
void	ft_pwd(t_cmd *cmd, t_shell *shell);
void	ft_unset(t_cmd *cmd, t_shell *shell);

/* * * * *
 *  env *
 * * * * */
t_env	*ft_search_env(char *var, t_shell *shell)

/* * * * * *
 *  exec  *
 * * * * * */
void	ft_exec(t_shell *shell);
