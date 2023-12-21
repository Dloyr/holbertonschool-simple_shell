#include "main.h"
/**
 * free_memory - free the memory of array
 * @array: array
 * @index: index
 */
void free_memory(char **array, int index)
{
	int i;

	for (i = 0; i < index; i++)
		free(array[i]);
	free(array);
}
