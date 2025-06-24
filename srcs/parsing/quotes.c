/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:29:08 by yel-mens          #+#    #+#             */
/*   Updated: 2025/06/24 11:37:54 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *ft_dup_from_line(int begin, int end, char *line)
{
	char	*word;
	int		i;
	int		sg_quote;
	int		db_quote;

	i = 0;
	sg_quote = 0;
	db_quote = 0;
	word = malloc(sizeof(char) * (end - begin) + 1);
	if (!word)
		return (NULL);
	while (begin < end)
	{
		if (line[begin] == '\'' && !db_quote)
			sg_quote = (sg_quote + 1) % 2;
		else if (line[begin] == '"' && !sg_quote)
			db_quote = (db_quote + 1) % 2;
		else if (line[begin] == '$' && !sg_quote)
			i = i + 1 - 1; // ajouter env avec verif de l'espace avant
		else
			word[i++] = line[begin];
		begin++;
	}
	word[i] = 0;
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
		if ((!sg_quote && !db_quote) && ft_isspace(line[*i]))
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

char	*ft_get_next_word(char *line, int *i)
{
	int		begin_word;
	int		end_word;

	while (ft_isspace(line[*i]))
		*i += 1;
	begin_word = *i;
	if (!ft_go_end_word(line, i))
		return (NULL);
	end_word = *i;
	return (ft_dup_from_line(begin_word, end_word, line));
}
