#include "sort.h"
/**
* partition - Fonction de partitionnement pour le tri rapide
* @array: Tableau d'entiers a trier
* @low: Indice de debut du sous-tableau
* @high: Indice de fin du sous-tableau (pivot)
* @size: Taille totale du tableau (pour print_array)
* Return: L’indice final du pivot apres le partitionnement
*/
int partition(int *array, int low, int high, int size)
{
int pivot = array[high];
int i = low, j, temp;

for (j = low; j < high; j++)
{
	  if (array[j] <= pivot)
	  {
		  if (i < j)
		  {
			  temp = array[i];
			  array[i] = array[j];
			  array[j] = temp;
			  print_array(array, size);
		  }
		  i++;
	  }
}
if (i < high)
{
	  temp = array[i];
	  array[i] = array[high];
	  array[high] = temp;
	  print_array(array, size);
}
return (i);
}

/**
* quick_sort_recursive - Fonction recursive de tri rapide
* @array: Tableau a trier
* @low: Indice de debut du sous-tableau
* @high: Indice de fin du sous-tableau
* @size: Taille totale du tableau (pour print_array)
* Return: neant
*/
void quick_sort_recursive(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
* quick_sort - Fonction principale du tri rapide
* @array: Tableau a trier
* @size: Taille du tableau
* Return: neant
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

quick_sort_recursive(array, 0, size - 1, size);
}
