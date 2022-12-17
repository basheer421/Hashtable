/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:25:12 by bammar            #+#    #+#             */
/*   Updated: 2022/12/18 02:07:26 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

unsigned int	ht_hash(t_ht *table, const char *key)
{
	unsigned int		value;
    unsigned int		i;
    unsigned int		key_len;

	
	value = 0;
	i = 0;
	key_len = ft_strlen(key);
    while (i < key_len) 
		value = value * 37 + key[i++];
	value = value % table->total_size;
    return (value);
}
