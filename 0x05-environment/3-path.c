#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	if (name == NULL || environ == NULL)
		return NULL;

	size_t name_len = strlen(name);

	for (char **env = environ; *env != NULL; env++)
	{
		if (strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
		{
			return &(*env)[name_len + 1];
		}
	}

	return NULL;
}

int main()
{
	const char *var_name = "PATH";
	char *value = _getenv(var_name);

	if (value != NULL)
	{
		printf("%s=%s\n", var_name, value);
	}
	else
	{
		printf("Environment variable %s not found\n", var_name);
	}

	return 0;
}

