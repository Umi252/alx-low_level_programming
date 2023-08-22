#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Pointer to the head of the doubly linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current, *temp;

	current = head;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

