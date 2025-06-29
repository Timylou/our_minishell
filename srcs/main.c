/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 08:26:31 by brturcio          #+#    #+#             */
/*   Updated: 2025/06/20 20:32:21 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_prompt(t_shell *shell)
{
	t_env	*logname;
	t_env	*hostname;
	t_env	*pwd;

	if (!isatty(STDIN_FILENO))
		return ;
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

static void ft_handle_line(char *line, char **env, t_shell *shell)
{
	ft_init_history(line, shell);
	if (ft_parse(line, shell))
		ft_process(env, shell);
	while (wait(NULL) != -1)
		;
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
			ft_handle_line(line, env, shell);
		else
			break ;
	}
	ft_free_shell(shell);
	if (isatty(STDIN_FILENO))
		ft_printf(YELLOW"\nSEE YOU SOON !\n"RST);
	return (EXIT_SUCCESS);
}
