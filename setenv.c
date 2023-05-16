#include "main.h"

/**
 * _setenv - set or add environment variable
 * @name: environnement variable's name
 * @value: environnement variable's value
 * @overwrite: don't change existing variables if zero
 *
 * Return: 0 on success, -1 otherwise.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i, keylen, found;
	char new[_POSIX_NAME_MAX];
	char *temp;

	keylen = strlen(name);
	found = 0;
	for (i = 0; environ[i] != NULL && !found; i++)
	{
		if (strncmp(name, environ[i], keylen) == 0 && environ[i][keylen] == '=')
		{
			found = 1;
			break;
		}
	}
	new[0] = '\0';
	strcat(new, name);
	strcat(new, "=");
	strcat(new, value);

	if (found && overwrite)
	{
		strncpy(environ[i], new, strlen(new) + 1);
		return (0);
	}

	if (!found)
	{
		temp = _strdup(new);
		environ[i] = temp;
		free(temp);
		environ[i + 1] = NULL;
	}

	return (0);
}
