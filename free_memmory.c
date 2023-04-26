#include "main.h"
/**
 * free_2d_ar- two dimensional array free
 * @argv: two dimensional array to be freed
 * @height: height of array
 *
 * Return: NULL
 */
void free_2d_ar(char **argv, int height)
{
	int h = height;

	if (argv != NULL)
	{
		for (; h >= 0; h--)
			free(argv[h]);
	}
	free(argv);
}
