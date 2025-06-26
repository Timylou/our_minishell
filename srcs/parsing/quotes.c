/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:29:08 by yel-mens          #+#    #+#             */
/*   Updated: 2025/06/24 14:02:44 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_issep(char c)
{
	if (c == 0 || ft_isspace(c) || c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

static void	ft_dollar(char *line, int *begin, char **word, t_shell *shell)
{
	char	*tab;
	t_env	*env;
	int		i;

	i = *begin + 1;
	while (!ft_issep(line[i]) && line[i] != '\'' && line[i] != '"')
		i++;
	tab = ft_substr(line, *begin + 1, i - *begin - 1);
	*begin = i - 1;
	env = ft_search_env(tab, shell);
	free(tab);
	if (!env)
		return ;
	tab = ft_strjoin(*word, env->value);
	free(*word);
	*word = malloc((ft_strlen(tab) + ft_strlen(line)) * sizeof(char));
	ft_strlcpy(*word, tab, ft_strlen(tab) + 1);
	free(tab);
}

static char	*ft_dup_from_line(int begin, int end, char *line, t_shell *shell)
{
	char	*word;
	int		i;
	int		sg_quote;
	int		db_quote;

	i = 0;
	sg_quote = 0;
	db_quote = 0;
	word = ft_calloc((end - begin) + 2, sizeof(char));
	while (begin < end)
	{
		if (line[begin] == '\'' && !db_quote)
			sg_quote = (sg_quote + 1) % 2;
		else if (line[begin] == '"' && !sg_quote)
			db_quote = (db_quote + 1) % 2;
		else if (line[begin] == '$' && !sg_quote && !ft_issep(line[begin + 1]))
			ft_dollar(line, &begin, &word, shell);
		else
			word[i++] = line[begin];
		while (word[i])
			i++;
		word[i + 1] = 0;
		begin++;
	}
	return (word);
}

static int	ft_go_end_word(char *line, int *i)
{
	int	sg_quote;
	int	db_quote;

	sg_quote = 0;
	db_quote = 0;
	while (line[*i])
	{
		if ((!sg_quote && !db_quote) && ft_issep(line[*i]))
			return (1);
		else if (!sg_quote && line[*i] == '"')
			db_quote = (db_quote + 1) % 2;
		else if (!db_quote && line[*i] == '\'')
			sg_quote = (sg_quote + 1) % 2;
		*i += 1;
	}
	if (!line[*i] && (sg_quote || db_quote))
	{
		ft_printf("minishell : Quotes not closed\n");
		return (0);
	}
	return (1);
}

char	*ft_get_next_word(char *line, int *i, t_shell *shell)
{
	int		begin_word;
	int		end_word;

	while (ft_isspace(line[*i]))
		*i += 1;
	begin_word = *i;
	if (!ft_go_end_word(line, i))
		return (NULL);
	end_word = *i;
	return (ft_dup_from_line(begin_word, end_word, line, shell));
}
