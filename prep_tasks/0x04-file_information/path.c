#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void check_command(char *command)
{
	if (access(command, F_OK) == 0)
		printf("%s: FOUND\n", command);
	else
		printf("%s: NOT FOUND\n", command);
}

int main()
{
	char *input_buffer = NULL;
	size_t buffer_size = 0;
	ssize_t chars;
	char *token;

	while (1)
	{
		printf("$ ");

		chars = getline(&input_buffer, &buffer_size, stdin);
		if (chars == -1)
		{
			perror("getline error");
			exit(EXIT_FAILURE);
		}

		input_buffer[strcspn(input_buffer, "\n")] = '\0'; // Remove trailing newline

		token = strtok(input_buffer, " \t\n");
		if (token != NULL && strcmp(token, "which") == 0)
		{
			token = strtok(NULL, " \t\n");
			while (token != NULL)
			{
				check_command(token);
				token = strtok(NULL, " \t\n");
			}
		}
		else
		{
			printf("Command doesn't exist\n");
		}
	}

	free(input_buffer);
	return 0;
}
