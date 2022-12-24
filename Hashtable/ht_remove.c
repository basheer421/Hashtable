/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:10:28 by bammar            #+#    #+#             */
/*   Updated: 2022/12/24 15:03:08 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

static	int	is_samekey(char *key1, char *key2)
{
	size_t	string_length;

	string_length = ft_strlen(key1);	
	if (string_length < ft_strlen(key2))
		string_length = ft_strlen(key2);
	return (ft_strncmp(key1, key2, string_length) == 0);
}

static void	remove_first_node(t_ht *table, unsigned int index)
{
	t_node			*node;

	node = table->array[index]; 
	if (node->next)
	{
		table->array[index] = table->array[index]->next;
		free(node->key);
		free(node->value);
	}
	else
	{
		node->key = NULL;
		node->value = NULL;
	}
	return ;
}

void	ht_remove(t_ht *table, const char *key)
{
	unsigned int	index;
	t_node			*node;
	t_node			*temp;
	char			*key_value;

	if (ht_isempty(table) || !ht_contains(table, key))
		return ;
	index = ht_hash(table, ft_strdup(key));
	node = table->array[index];
	key_value = ft_strdup(key);
	if (!key_value)
		return ;
	table->size--;
	if (is_samekey(node->key, key_value))
	{
		remove_first_node(table, index);
		free(key_value);
		return ;
	}
	while (node->next)
	{
		if (is_samekey(node->next->key, key_value))
		{
			temp = node->next;
			node->next = node->next->next;
			free(temp->value);
			free(temp->key);
			free(temp);
			return ;
		}
		node = node->next;
	}
	node->key = NULL;
	node->value = NULL;
}
