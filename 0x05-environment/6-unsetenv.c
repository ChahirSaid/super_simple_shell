#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
	if (name == NULL)
	{
		fprintf(stderr, "Invalid argument\n");
		return -1;
	}

	size_t name_len = strlen(name);

	char **env_ptr = environ;
	char **write_ptr = environ;

	while (*env_ptr != NULL)
	{
		if (strncmp(*env_ptr, name, name_len) == 0 && (*env_ptr)[name_len] == '=')
		{
			// Skip the entry to be deleted by not copying it
			env_ptr++;
		}
		else
		{
			// Copy the current entry to the write pointer and advance both pointers
			*write_ptr = *env_ptr;
			env_ptr++;
			write_ptr++;
		}
	}

	// Terminate the modified environment by setting the next pointer of the last valid entry to NULL
	*write_ptr = NULL;

	return 0;
}

int main()
{
	// Example usage
	_unsetenv("MY_VAR");

	// Print the modified environment
	char **env_ptr = environ;
	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}

	return 0;
}
