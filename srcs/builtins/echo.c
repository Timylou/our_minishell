/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:40:32 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/04 12:29:40 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_is_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (1);
	i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_echo_printf(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	return (0);
}

int	ft_echo_builtins(char **cmd)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (!*cmd || !cmd[0])
		return (1);
	while (cmd[i] && !ft_is_newline(cmd[i]))
	{
		newline = 0;
		i++;
	}
	ft_echo_printf(cmd + i);
	if (newline)
		ft_putstr_fd("\n", 1);
	return (0);
}
