#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **splitstring(char *str)
{
	char *token, **tkns = NULL;
	int i = 0;

	token = strtok(str, " \t\n");
	while(token != NULL)
	{
		i++;
		tkns = realloc(tkns, i * sizeof(char *));
		if (tkns == NULL)
		{
			perror("allocation error");
			exit(EXIT_FAILURE);
		}
		tkns[i -1] = token;
		token = strtok(NULL, " \t\n");
	}
	for (i=0; tkns[i]; i++)
		printf("%s\n", tkns[i]);
	return tkns;
}
int main(int argc, char **argv)
{
	char *buffer = NULL, **tkns;
	size_t s_buffer = 0;
	int n_char = 0, i=0;
	int s_token = 0;

	write(1, "$ ", 2);
	n_char = getline(&buffer, &s_buffer, stdin);
	if (n_char == EOF)
	{
		perror("error!");
		exit(EXIT_FAILURE);
	}
	buffer[n_char -1] = '\0';
	tkns = splitstring(buffer);

	return 0;
}

