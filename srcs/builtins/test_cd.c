/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:52:58 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/06 17:53:00 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Simular estructura mínima de t_shell
typedef struct s_shell
{
	t_env *env;             // si necesitas usar env, puedes dejarlo en NULL para test
	int exit_status;
} t_shell;

// Simular estructura mínima de t_cmd
typedef struct s_cmd
{
	char **args;
} t_cmd;

int main(int argc, char **argv)
{
	t_shell shell;
	t_cmd   cmd;
	char    *cwd;

	// Simular el comando cd [arg]
	cmd.args = malloc(sizeof(char *) * 3);
	if (!cmd.args)
		return (1);
	cmd.args[0] = "cd";
	cmd.args[1] = (argc > 1) ? argv[1] : NULL;
	cmd.args[2] = NULL;

	// Ejecutar cd
	shell.env = NULL;
	shell.exit_status = 0;
	ft_cd_builtins(&cmd, &shell);

	// Mostrar resultado
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		printf("Directorio actual: %s\n", cwd);
		free(cwd);
	}

	free(cmd.args);
	return (0);
}
