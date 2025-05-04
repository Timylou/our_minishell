/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 08:26:31 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/04 16:47:47 by yel-mens         ###   ########.fr       */
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
		ft_printf(HGRN"%s"RST, logname->data + 8);
	if (hostname)
		ft_printf(CYAN"@%s"RST, hostname->data + 5);
	if (logname || hostname)
		write(1, ":", 1);
	if (pwd)
		ft_printf(HMAG"%s"RST, pwd->data + 4);
	write(1, "$ ", 2);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	char	*line;

	// (void) argc;
	(void) argv;
	printbanner();
	shell = init_shell(env);
	while (argc > 0)
	{
		ft_print_prompt(shell);
		line = get_next_line(STDIN_FILENO);
		ft_parse(line, shell);
		free(line);
		ft_process(env, shell);
		while (wait(NULL) != -1)
		;
		argc--;
	}
	ft_free_shell(shell);
	return (EXIT_SUCCESS);
}
