#include "search_algos.h"
/**
 * find_index - find first index
 * @array: array
 * @start_index: starting index
 * @end_index: ending index
 * @value: value
* Return: -1 or index
 */
int find_index(int *array, int start_index, int end_index, int value)
{
	int middle;
	int i;

	if (end_index >= start_index)
	{
		printf("Searching in array: ");
		for (i = start_index; i <= end_index; i++)
		{
			printf("%d", array[i]);
			if (i != end_index)
			printf(", ");
		}
		printf("\n");
		middle = start_index + (end_index - start_index) / 2;
		if (array[middle] == value && array[middle - 1] != value)
			return (middle);
		if (array[middle] >= value)
			return (find_index(array, start_index, middle, value));
		if (array[middle] <= value)
			return (find_index(array, middle + 1, end_index, value));
	}
	return (-1);
}

/**
 * advanced_binary - search for value in sorted array of ints
 * @array: sorted array
 * @size: size
 * @value: value
 * Return: -1 or index
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (find_index(array, 0, size - 1, value));
}
