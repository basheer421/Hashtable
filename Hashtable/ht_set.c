/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:28:18 by bammar            #+#    #+#             */
/*   Updated: 2022/12/23 23:05:55 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

int	ht_set(t_ht *table, char *key, void *value)
{
	unsigned int	index;
	t_node			*node;

	if (ht_contains(table, key))
		return (0);
	index = ht_hash(table, key);
	node = table->array[index];
	if (node->key == NULL)
	{
		node->key = key;
		node->value = value;
		table->size++;
		return (1);
	}
	while (node->next)
		node = node->next;
	node->next = malloc(sizeof(t_node));
	if (!node->next)
		return (-1);
	node->key = key;
	node->value = value;
	node->next = NULL;
	table->size++;
	return (1);
}
