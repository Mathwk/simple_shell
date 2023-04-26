#include "main.h"
/**
 * excute_in - process the arguments passed from shel
 * @argv: arguments passsed
 *
 * Return: nothing
 */
void excute_in(char **argv)
{
	if (argv != NULL)
	{
		if (execve(full_path(argv[0]), argv, NULL) == -1)
			perror("(incorrect input) ");
	}
}
