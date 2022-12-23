/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:52:51 by bammar            #+#    #+#             */
/*   Updated: 2022/12/23 23:12:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

void	*ht_get(t_ht *table, const char *key)
{
	unsigned int	index;
	int				string_length;
	t_node			*node;

	if (ht_isempty(table))
		return (NULL);
	index = ht_hash(table, key);
	node = table->array[index];
	while (node)
	{
		string_length = ft_strlen(node->key);
		if (string_length < (int)ft_strlen(key))
			string_length = ft_strlen(key);
		if (ft_strncmp(node->key, key, string_length) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
