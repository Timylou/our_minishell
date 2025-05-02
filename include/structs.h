/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:03:15 by yel-mens          #+#    #+#             */
/*   Updated: 2025/05/02 12:11:57 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	struct s_env	prev;
}	t_env;

typedef struct s_shell
{
	t_cmd	*cmds;
	t_env	*env;
	int		exit_status;
}	t_shell;

/* * * * *
*  env *
* * * * */

void	ft_init_env(char **env, t_shell *shell);
t_env	*ft_search_env(char *var, t_shell *shell);
void	ft_append_env(char *data, t_shell *shell);
void	ft_unset_env(t_env *to_delete, t_shell *shell);

#endif