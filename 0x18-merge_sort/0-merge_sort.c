#include "sort.h"
/**
 * merge_sort - sort an array
 * @array: array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i = 0;

	copy = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	split(array, 0, size, copy);
	free(copy);
}
/**
 *split - split
 *@array: array
 *@copy: copy of array
 *@start: starting index
 *@end: ending
 */
void split(int *array, int start, int end, int *copy)
{
	int middle = (start + end) / 2;
	int pointer = 0;

	if (end - start <= 1)
		return;

	split(copy, start, middle, array);
	split(copy, middle, end, array);
	printf("Merging...\n");

	printf("[left]: ");
	for (pointer = start; pointer < middle; pointer++)
	{
		printf("%d", copy[pointer]);
		if (pointer < middle - 1)
			printf(", ");
	}

	printf("\n[right]: ");
	for (pointer = middle; pointer < end; pointer++)
	{
		printf("%d", copy[pointer]);
		if (pointer < end - 1)
			printf(", ");
	}

	merge(array, start, middle, end, copy);

	printf("\n");
	printf("[Done]: ");
	for (pointer = start; pointer < end; pointer++)
	{
		printf("%d", array[pointer]);
		if (pointer < end - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 * merge - merge
 * @array: array
 * @copy: copy
 * @start: starting index
 * @end:  ending index
 * @mid: mid index
 */
void merge(int *array, int start, int mid, int end, int *copy)
{
	int s = start;
	int m = mid;
	int pointer = 0;

	for (pointer = start; pointer < end; pointer++)
	{

		if (s < mid && (m >= end || copy[s] <= copy[m]))
		{
			array[pointer] = copy[s];
			s = s + 1;
		}
		else
		{
			array[pointer] = copy[m];
			m = m + 1;
		}
	}
}
