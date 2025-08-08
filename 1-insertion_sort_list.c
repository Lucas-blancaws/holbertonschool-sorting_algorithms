#include "sort.h"

/**
 * swap - Échange deux nœuds adjacents (node1 <-> node2)
 * @list: Pointeur vers le début de la liste
 * @node1: Nœud avant
 * @node2: Nœud après (node1->next)
 */
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2 || node1->next != node2 || node2->prev != node1)
		return;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
	print_list(*list);
}

/**
 * insertion_sort_list - Trie une liste double chaînée avec insertion sort
 * @list: Double pointeur vers le début de la liste
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !*list || !(*list)->next)
	return;

	current = (*list)->next;
	while (current)
	{

		while (current->prev && current->n < current->prev->n)
		{
			swap(list, current->prev, current);
		}
		current = current->next;
	}
}
