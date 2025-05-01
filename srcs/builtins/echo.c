/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:40:32 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/01 15:15:20 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (1);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	echo_printf(char **cmd)
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

int	echo_builtins(char **cmd)
{
	int	i;
	int	newline;

	i = 0;
	newline = 0;
	if (!*cmd || !cmd[0])
		return (1);
	while (cmd[i])
	{
		if (!is_newline(cmd[i]))
			newline = 1;
		i++;
	}
	if (newline)
		echo_printf(cmd + 2);
	else
	{
		echo_printf(cmd + 1);
		ft_putstr_fd("\n", 1);
	}
	return (0);
}
