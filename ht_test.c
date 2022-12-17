/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:57:07 by bammar            #+#    #+#             */
/*   Updated: 2022/12/18 02:08:38 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hashtable/ht.h"
#include <stdio.h>

int main(void)
{
	t_ht	*table;
 
	table = ht_new(100);
	if (!table)
		return (1);
	int n = 10;
	ht_set(table, "hello", &n);
	ht_set(table, "hhi", "world2");
	int *x = ht_get(table, "hello");
	char * x1 = ht_get(table, "hhi");
	printf("%d\n", *x);
	printf("%s\n", x1);
	return (0);
}
