/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:10:28 by bammar            #+#    #+#             */
/*   Updated: 2022/12/18 02:27:31 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

void	ht_remove(t_ht *table, const char *key)
{
	unsigned int	index;
	t_node			*node;
	t_node			*temp;

	if (ht_isempty(table))
		return ;
	index = ht_hash(table, key)	;
	node = table->array[index];
	while (node)
	{
		if (node->key == key)
		{
			temp = table->array[index];
			node->key = temp->key;
			node->value = temp->value;
			table->array[index] = table->array[index]->next;
			if (table->array[index] == NULL)
				temp->key = NULL;
			else
				free(temp);
			return ;
		}
		node = node->next;
	}
	
}