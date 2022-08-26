/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:13:54 by bammar            #+#    #+#             */
/*   Updated: 2022/08/26 05:01:29 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hashtable.h"

static unsigned int	hash(const char *key) {
    unsigned long int	value;
    unsigned int		i;
    unsigned int		key_len;

	value = 0;
	i = 0;
	key_len = ft_strlen(key);
    while (i < key_len) 
		value = value * 37 + key[i++];
    value = value % TABLE_SIZE;
    return (value);
}

Hashtable	*create_Hashtable(void)
{
	Hashtable		*table;
	unsigned int	i;			

	table = malloc(sizeof(Hashtable) * 1);
	if (!table)
		return (NULL);
	table->lists = malloc(sizeof(t_list *) * TABLE_SIZE);
	if (!table->lists)
		return (NULL);
	i = 0;
	while (i < TABLE_SIZE)
		table->lists[i++] = NULL;
	return (table);
}

void	free_Hashtable(Hashtable *table)
{
	if (!table)
		return ;
	if (table->lists)
	{
		ft_lstiter(*(table->lists), free);
		free(table->lists);
	}
	free(table);
}

static Node	*new_Node(const char *key, const char *value)
{
	Node	*node;

	node = malloc(sizeof(Node *));
	node->key = (char *)key;
	node->value = (char *)value;
	if (!node)
		return (NULL);
	return (node);
}

void	Hashtable_set(Hashtable *table, const char *key, const char *value)
{
	unsigned int	position;
	t_list			*list;

	position = hash(key);
	list = table->lists[position];
	if (!list)
	{
		list->content = new_Node(key, value);
		list->next = NULL;
		return ;
	}
	while (list->next != NULL)
	{
		if (ft_strncmp(((Node *)(list->content))->key, key, ft_strlen(key)) == 0)
		{
			((Node *)(list->content))->value = (char *)value;
			return ;
		}
		else
		{
			ft_lstadd_back(&list, ft_lstnew(new_Node(key, value)));
			return ;
		}
		list = list->next;
	}
}

char	*Hashtable_get(Hashtable *table, const char *key)
{
	unsigned int	position;
	t_list			*list;

	position = hash(key);
	list = table->lists[position];
	if (!list)
		return (NULL);
	while (list->next != NULL)
	{
		if (ft_strncmp(((Node *)(list->content))->key, key, ft_strlen(key)) == 0)
			return (((Node *)(list->content))->value);
		list = list->next;
	}
	return (NULL);
}
// /*
int main(void)
{
	Hashtable	*table;

	table = create_Hashtable();
	Hashtable_set(table, "name", "Basheer");
	puts(Hashtable_get(table, "name"));
	free_Hashtable(table);
	return (0);
}
// */