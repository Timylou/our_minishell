#include "minishell.h"

void	ft_close(t_cmd *cmds)
{
	while (cmds)
	{
		close(cmds->in);
		close(cmds_>out);	
		cmds = cmds->next;
	}
}

void	ft_free_array(char **array)
{
	int	i;
	
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

static void	ft_free_cmds(t_cmd *cmds)
{
	t_cmd	*next_cmd;

	ft_close(cmds);
	next_cmd = NULL;
	while (cmds)
	{
		next_cmd = cmds->next;
		ft_free_array(cmds->args);
		free(cmds);
		cmds = next_cmd;
	}
}

void	ft_error(char *msg, t_shell *shell)
{
	if (!shell)
		exit(EXIT_FAILURE);
	perror(msg);
	if (shell->cmds)
		ft_free_cmds(shell->cmds);
}
