#include "main.h"
/**
 * string_split - splits string into pieces based on the del
 * @str: input string
 * @del: delimerate/ criteria for dividing the string
 * @length: length of str
 *
 * Return: splited string array
 */
char **string_split(char *str, char del, int length)
{
	int i, j, count;
	char **portion, str_t[98];

	portion = malloc(sizeof(char *) * length);
	for (i = 0, count = 0; str[i + 1] != '\0'; i++)
	{
		if (str[i] == del)
			continue;
		for (j = 0; !(str[i + 1] == '\0' || str[i] == del); j++, i++)
			str_t[j] = str[i];
		portion[count] = malloc(sizeof(char) * strlen(str_t));
		strcpy(portion[count], str_t);
		count++;
		for (j = 0; j < 98; j++)
			str_t[j] = '\0';
	}
	return (portion);
}
