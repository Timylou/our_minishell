/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:45:47 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/04 12:28:52 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd_builtins(char **cmd)
{
	char	*rute;

	(void)cmd;
	rute = getcwd(NULL, 0);
	if (!rute)
	{
		ft_putstr_fd("getcwd failed", 2);
		return(1);
	}
	else
	{
		ft_putstr_fd(rute, 1);
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
