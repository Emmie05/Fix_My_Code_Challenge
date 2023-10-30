#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    
    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        *head = current->next;
        if (current->next)
            current->next->prev = NULL;
        free(current);
        return (1);
    }

    while (index > 0 && current)
    {
        current = current->next;
        index--;
    }

    if (current == NULL)
        return (-1);

    current->prev->next = current->next;

    if (current->next)
        current->next->prev = current->prev;

    free(current);

    return (1);
}
