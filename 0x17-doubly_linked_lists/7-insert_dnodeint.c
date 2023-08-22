#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at
 * a given position
 *
 * @h: head of the list
 * @idx: index of the new node
 * @n: value of the new node
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int count = 0;

	if (h == NULL)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *h;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	current = *h;
	while (current)
	{
		if (count == idx - 1)
		{
			new_node->next = current->next;
			if (current->next)
				current->next->prev = new_node;
			current->next = new_node;
			new_node->prev = current;
			return (new_node);
		}
		current = current->next;
		count++;
	}

	free(new_node);
	return (NULL);
}

