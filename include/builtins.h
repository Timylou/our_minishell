/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:18:42 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/14 17:35:50 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "structs.h"
# include "minishell.h"

# define PATH_MAX 4096

int		ft_is_builtin(char *arg);
int		ft_is_builtin_no_fork(char *arg);
int		ft_no_fork(t_cmd *cmd, t_shell *shell);
void	ft_exec_builtins(t_cmd *cmd, t_shell *shell);

int		ft_echo_builtins(t_cmd *cmd);
int		ft_pwd_builtins(t_cmd *cmd);
int		ft_env_builtins(t_cmd *cmd, t_env *env);
int		ft_cd_builtins(t_cmd *cmd, t_shell *shell);
void	ft_exit_builtins(t_cmd *cmd, t_shell *shell);
int		ft_export_builtins(t_shell *shell);
t_env	*ft_cread_env_copy(t_env *env);
void	ft_sort_env_copy(t_env *head);
void	ft_export_error_msj(char *arg, char *msj);
int		ft_parsing_export_arg(char *arg);
int		ft_compare_nom(char *str1, char *str2);
int		ft_var_exists(t_shell *shell);
int		ft_check_equal(char *arg);


char	*ft_get_val(char *var, t_shell *shell);
char	*ft_update_env(char *var, char *data, t_shell *shell);
int		ft_cd_path(char *arg, t_shell *shell);

#endif
