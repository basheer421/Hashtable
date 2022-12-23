/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:25:12 by bammar            #+#    #+#             */
/*   Updated: 2022/12/23 23:20:23 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

unsigned int	ht_hash(t_ht *table, const char *key)
{
	unsigned int	hash;

	hash = 5381;
	while (*key)
		hash = ((hash << 5) + hash) + *key++;
	return (hash % (table->total_size - 1));
}
