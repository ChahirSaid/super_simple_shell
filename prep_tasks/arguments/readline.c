#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t s_buffer = 0;
	int n_char = 0;

	write(1, "$ ", 2);
	n_char = getline(&buffer, &s_buffer, stdin);
	if (n_char == EOF)
		perror("error!");
	buffer[n_char -1] = '\0';
	printf("%s\n", buffer);

	return 0;
}
