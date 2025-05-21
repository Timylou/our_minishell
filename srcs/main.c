/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 08:26:31 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/20 09:57:49 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_prompt(t_shell *shell)
{
	t_env	*logname;
	t_env	*hostname;
	t_env	*pwd;

	logname = ft_search_env("LOGNAME", shell);
	hostname = ft_search_env("NAME", shell);
	pwd = ft_search_env("PWD", shell);
	if (logname)
		ft_printf(HGRN"%s"RST, logname->data + 8);
	if (hostname)
		ft_printf(CYAN"@%s"RST, hostname->data + 5);
	if (logname || hostname)
		write(1, ":", 1);
	if (pwd)
		ft_printf(HMAG"%s"RST, pwd->data + 4);
	write(1, "$\t", 2);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*line;

	(void) argc;
	(void) argv;
	printbanner();
	shell = init_shell(env);
	while (shell)
	{
		ft_print_prompt(shell);
		line = ft_readline(shell);
		if (line)
		{
			ft_init_history(line, shell);
			ft_parse(line, shell);
			ft_process(env, shell);
			while (wait(NULL) != -1)
				;
		}
		else
			break ;
	}
	ft_free_shell(shell);
	ft_printf(YELLOW"SEE YOU SOON !\n"RST);
	return (EXIT_SUCCESS);
}
