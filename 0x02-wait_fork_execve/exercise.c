#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return 1;
		}
		if (pid == 0)
		{
			// Child process
			printf("Child %d executing ls -l /tmp:\n", getpid());
			char *argv[] = {"ls", "-l", "/tmp", NULL};
			if (execvp("ls", argv) == -1)
				{
					perror("Error:");
					return 1;
				}
		}
		else
		{
			// Father process
			int status;
			wait(&status);
			if (WIFEXITED(status))
			{
				printf("Child %d exited with status %d\n", pid, WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status))
			{
				printf("Child %d terminated by signal %d\n", pid, WTERMSIG(status));
			}
		}
	}

	return 0;
}
