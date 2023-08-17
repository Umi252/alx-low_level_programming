#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a dlistint_t list.
 * @head: Pointer to a pointer to the head of the doubly linked list.
 * @index: Index of the node that should be deleted.
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current, *prev, *next;
    unsigned int count = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    if (index == 0)
    {
        *head = current->next;
        if (current->next != NULL)
            current->next->prev = NULL;
        free(current);
        return (1);
    }

    while (current != NULL)
    {
        if (count == index)
        {
            prev = current->prev;
            next = current->next;
            if (prev != NULL)
                prev->next = next;
            if (next != NULL)
                next->prev = prev;
            free(current);
            return (1);
        }
        current = current->next;
        count++;
    }

    return (-1);
}


