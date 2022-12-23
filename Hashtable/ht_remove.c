/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:10:28 by bammar            #+#    #+#             */
/*   Updated: 2022/12/24 01:46:22 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

void	ht_remove(t_ht *table, const char *key)
{
	unsigned int	index;
	t_node			*node;
	t_node			*temp;
	char			*key_value;
	size_t			string_length;

	if (ht_isempty(table) || !ht_contains(table, key))
		return ;
	index = ht_hash(table, ft_strdup(key));
	node = table->array[index];
	key_value = ft_strdup(key);
	if (!key_value)
		return ;
	table->size--;
	while (node->next)
	{
		string_length = ft_strlen(node->next->key);	
		if (string_length < ft_strlen(key_value))
			string_length = ft_strlen(key_value);
		if (ft_strncmp(node->next->key, key_value, string_length) == 0)
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