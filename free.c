#include "main.h"

void free_memory(char **array, int index)
{
	int i;

	for (i = 0; i < index; i++)
		free(array[i]);
	free(array);
}
