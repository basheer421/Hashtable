/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:04:33 by bammar            #+#    #+#             */
/*   Updated: 2022/12/24 15:26:26 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HT_H
# define HT_H

# include "../libft/libft.h"

typedef struct s_node
{
	char			*key;
	void			*value;
	struct s_node	*next;
}					t_node;

typedef struct s_ht
{
	t_node			**array;
	size_t			total_size;
	size_t			size;
}					t_ht;

t_ht				*ht_new(size_t size);
unsigned int		ht_hash(t_ht *table, char *key);
int					ht_set(t_ht *table, char *key, void *value);
void				*ht_get(t_ht *table, const char *key);
int					ht_contains(t_ht *table, const char *key);
int					ht_isempty(t_ht *table);
void				ht_remove(t_ht *table, const char *key);
void				ht_replace(t_ht *table, char *key, void *new_value);
void				ht_clear(t_ht *table);
void				ht_destroy(t_ht *table);

#endif