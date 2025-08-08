#include "sort.h"
/**
* bubble_sort - Trie un tableau d'entiers dans l'ordre croissant
* @array: Pointeur vers le tableau d'entiers a trier
* @size: Taille du tableau
* Return: neant
*/
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;

/* Verifie tableau valide et s'il contient au moins 2 elements */
if (array == NULL || size < 2)
	return;

/* Boucle exterieure : nombre total de passes */
for (i = 0; i < size - 1; i++)
{
	/* Boucle intérieure : compare les elements non tries */
	for (j = 0; j < size - i - 1; j++)
	{
	/* Si deux elements sont dans le mauvais ordre, on les echange */
	if (array[j] > array[j + 1])
	{
		/* Echange des deux elements */
		temp = array[j];
		array[j] = array[j + 1];
		array[j + 1] = temp;

		/* Affiche l'etat du tableau apres chaque echange */
		print_array(array, size);
	}
	}
}
}
