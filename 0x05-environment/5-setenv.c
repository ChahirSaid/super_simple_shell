#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	size_t name_len = strlen(name);
	size_t value_len = strlen(value);
	size_t total_len = name_len + value_len + 2; // +2 for '=' and null terminator

	char *new_entry = (char *)malloc(total_len);
	if (new_entry == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return -1;
	}

	snprintf(new_entry, total_len, "%s=%s", name, value);

	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		if (strncmp(*env_ptr, name, name_len) == 0 && (*env_ptr)[name_len] == '=')
		{
			if (overwrite)
			{
				free(*env_ptr);
				*env_ptr = new_entry;
				return 0;
			}
			else
			{
				free(new_entry);
				return 0;
			}
		}
		env_ptr++;
	}

	// If the variable was not found, append the new entry to the environment
	char **new_env = (char **)realloc(environ, (env_ptr - environ + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		free(new_entry);
		return -1;
	}

	new_env[env_ptr - environ] = new_entry;
	new_env[env_ptr - environ + 1] = NULL;

	environ = new_env;

	return 0;
}

int main()
{
	// Example usage
	_setenv("MY_VAR", "my_value", 1);
	_setenv("ANOTHER_VAR", "another_value", 0);

	// Print the modified environment
	char **env_ptr = environ;
	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}

	return 0;
}
