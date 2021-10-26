#include "sort.h"

/**
 * partition - Partitions the array to segments
 * @array: Array to be sorted
 * @low: Lowest position of the partition
 * @high: Highest position of the partition
 * @size: Size of the array
 * Return: Position to perform recursion
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, save;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			save = array[i];
			array[i] = array[j];
			array[j] = save;
			if (i != j)
				print_array(array, size);
		}
	}
	save = array[i + 1];
	array[i + 1] = array[j];
	array[j] = save;
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * quick - Implements quicksort algorithm recursively
 * @array: Array to be sorted
 * @low: Lowest position
 * @high: Highest position
 * @size: Size of the array
 */

void quick(int *array, int low, int high, size_t size)
{
	int pos;

	if (low < high)
	{
		pos  = partition(array, low, high, size);
		quick(array, low, pos - 1, size);
		quick(array, pos + 1, high, size);
	}
}

/**
 * quick_sort - Implements the quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick(array, 0, (int)size - 1, size);
}
