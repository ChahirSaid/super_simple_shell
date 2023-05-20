#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 1024

int main()
{
    char *buffer = NULL;
    size_t buffer_s = 0;

    while (1)
    {
        printf("$ ");

        ssize_t n_char = getline(&buffer, &buffer_s, stdin);
        if (n_char == -1)
        {
            perror("getline error");
            exit(EXIT_FAILURE);
        }

        buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline

        char *args[MAX_ARGS];
        int argc = 0;

        char *token = strtok(buffer, " \t\n");
        while (token != NULL && argc < MAX_ARGS - 1)
        {
            args[argc++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[argc] = NULL;

        if (argc > 0)
        {
            pid_t pid = fork();
            if (pid == -1)
            {
                perror("fork error");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                // Child process
                if (execvp(args[0], args) == -1)
                {
                    perror("execvp error");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                // Parent process
                int status;
                wait(&status);
            }
        }
    }

    free(buffer);
    return 0;
}

