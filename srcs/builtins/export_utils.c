/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:37:00 by brturcio          #+#    #+#             */
/*   Updated: 2025/05/12 14:33:00 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_lstnew_env(void *content)
{
	t_env	*cont;

	cont = malloc(sizeof(t_env));
	if (!cont)
		return (NULL);
	cont->data = ft_strdup(content);
	if (!cont->data)
		return (NULL);
	cont->next = NULL;
	cont->prev = NULL;
	return (cont);
}

static void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*last_node;

	if (!*lst)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new;
		new->prev = last_node;
	}
}

t_env	*ft_cread_env_copy(t_env *env)
{
	t_env	*env_copy;
	t_env	*new_nodo;

	env_copy = NULL;
	new_nodo = NULL;
	while (env)
	{
		new_nodo = ft_lstnew_env(env->data);
		if (!new_nodo)
		{
			ft_free_env(env_copy);
			return (NULL);
		}
		ft_lstadd_back_env(&env_copy, new_nodo);
		env = env->next;
	}
	return (env_copy);
}

void	ft_sort_env_copy(t_env *head)
{
	t_env	*current;
	char	*tmp;
	int		swapped;

	if (!head)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = head;
		while (current && current->next)
		{
			if (ft_strcmp(current->data, current->next->data) > 0)
			{
				tmp = current->data;
				current->data = current->next->data;
				current->next->data = tmp;
				swapped = 1;
			}
			current = current->next;
		}
	}
}
