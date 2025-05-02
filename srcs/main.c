/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 08:26:31 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/02 12:14:58 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_prompt(t_shell *shell)
{
	t_env	*logname;
	t_env	*hostname;
	t_env	*pwd;

	logname = ft_search_env("LOGNAME", shell);
	hostname = ft_search_env("NAME", shell);
	pwd = ft_search_env("PWD", shell);
	if (logname)
		ft_printf("%s", logname->data);
	if (hostname)
		ft_printf("@%s", hostname->data);
	if (logname || hostname)
		write(1, ":", 1);
	if (pwd)
		ft_printf("%s", pwd->data);
	write(1, "$", 1);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	printbanner();
	shell = init_shell(env);
	while (shell)
	{
		ft_print_prompt(shell);
	}
	return (0);
}
