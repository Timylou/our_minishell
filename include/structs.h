/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:03:15 by yel-mens          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/05/04 15:06:22 by brturcio         ###   ########.fr       */
=======
/*   Updated: 2025/05/04 14:16:45 by brturcio         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	char			**data;
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

/* * * *  *
*  free *
* * * * * */

void	ft_free_array(char **array);
void	ft_free_env(t_env *env);
void	ft_error(char *msg, int exit_code, t_shell *shell);
void	ft_free_shell(t_shell *shell);

#endif
