#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[], char *env[])
{
	printf("Address of env parameter: %p\n", (void *)&env);
	printf("Address of environ variable: %p\n", (void *)&environ);

	return 0;
}

