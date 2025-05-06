/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:18:42 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/06 15:31:25 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "structs.h"
# include "minishell.h"

# define PATH_MAX 4096

int		ft_is_builtin(char *arg);
void	ft_exec_builtins(t_cmd *cmd, t_shell *shell);

int		ft_echo_builtins(t_cmd *cmd);
int		ft_pwd_builtins(t_cmd *cmd);
int		ft_env_builtins(t_cmd *cmd, t_env *env);
int		ft_cd_builtins(t_cmd *cmd, t_shell *shell);

char	*ft_get_val(char *var, t_shell *shell);
char	*ft_update_env(char *var, char *data, t_shell *shell);
int		ft_cd_path(char *arg, t_shell *shell);

#endif
