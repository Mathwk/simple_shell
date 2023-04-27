#include "main.h"
/**
 * full_path - pull path for search of command
 * @cmnd: command to be searched
 *
 * Return: full path of the command
 */
char *full_path(char *cmnd)
{
	int i, count;
	char **path, *paths, *file_loc;
	struct stat statbuf;

	if (stat(cmnd, &statbuf) == 0)
		return (cmnd);
	paths = getenv("PATH");
	if (paths != NULL)
	{
		for (i = 0, count = 1; paths[i] != '\0'; i++)
			if (paths[i] == ':')
				count++;
		path = string_split(paths, ':', count);
		for (i = 0; path[i] != NULL; i++)
		{
			file_loc = malloc(strlen(cmnd) + strlen(path[i]) + 2);
			strcpy(file_loc, path[i]);
			strcat(file_loc, "/");
			strcat(file_loc, cmnd);
			strcat(file_loc, "\0");
			if (stat(file_loc, &statbuf) == 0)
			{
				return (file_loc);
			}
			free(file_loc);
		}
	}
	return (NULL);
}
