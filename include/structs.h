/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:03:15 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/06 18:38:43 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cmd
{
	char			**args;
	int				in;
	int				out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_shell
{
	t_cmd	*cmds;
	t_env	*env;
	char	**path;
	int		exit_status;
}	t_shell;

/* * * *  *
*  shell *
* * * * * */

t_shell	*init_shell(char **env);

/* * * * *
*  env *
* * * * */

void	ft_init_env(char **env, t_shell *shell);
t_env	*ft_search_env(char *var, t_shell *shell);
void	ft_append_env(char *data, t_shell *shell);
void	ft_unset_env(t_env *to_delete, t_shell *shell);

/* * * *
* cmd *
* * * * */

t_cmd	*ft_init_cmd(void);

/* * * *  * 
*  free *
* * * * * */

void	ft_free_array(char **array);
void	ft_free_env(t_env *env);
void	ft_error(char *msg, int exit_code, t_shell *shell);
void	ft_free_cmds(t_cmd *cmds);
void	ft_free_shell(t_shell *shell);

#endif