/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:12:28 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/06 14:45:41 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_path(char *arg, t_shell *shell)
{
	char	*pwd;

	pwd = ft_get_val("PWD", shell);
	if (access(arg, F_OK) == -1)
	{
		ft_putstr_fd("minishell: cd : No such file or directory", STDERR_FILENO);
		free(pwd);
		return(1);
	}
}
