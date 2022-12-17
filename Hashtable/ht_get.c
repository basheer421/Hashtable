/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:52:51 by bammar            #+#    #+#             */
/*   Updated: 2022/12/18 01:57:05 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

void	*ht_get(t_ht *table, const char *key)
{
	unsigned int	index;
	t_node			*node;

	if (ht_isempty(table))
		return (NULL);
	index = ht_hash(table, key);
	node = table->array[index];
	while (node)
	{
		if (node->key == key)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}