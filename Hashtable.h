/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:04:33 by bammar            #+#    #+#             */
/*   Updated: 2022/08/26 04:57:04 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

#include "libft/libft.h"

#define TABLE_SIZE 100

typedef struct Hashtable
{
	t_list	**lists;
} Hashtable;

typedef struct Node
{
	char	*key;
	void	*value;
} Node;

void		Hashtable_set(Hashtable *table, const char *key, const char *value);
char		*Hashtable_get(Hashtable *table, const char *key);
Hashtable	*create_Hashtable(void);
void		free_Hashtable(Hashtable *table);

#endif