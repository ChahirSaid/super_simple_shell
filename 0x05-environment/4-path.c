#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

typedef struct Node
{
	char *directory;
	struct Node *next;
} Node;

Node *build_path_list()
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not found\n");
		return NULL;
	}

	Node *head = NULL;
	Node *prev = NULL;

	char *token = strtok(path, ":");

	while (token != NULL)
	{
		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->directory = strdup(token);
		new_node->next = NULL;

		if (prev == NULL)
		{
			head = new_node;
		}
		else
		{
			prev->next = new_node;
		}

		prev = new_node;
		token = strtok(NULL, ":");
	}

	return head;
}

void print_path_list(Node *head)
{
	Node *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}
}

void free_path_list(Node *head)
{
	Node *current = head;
	Node *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->directory);
		free(current);
		current = next;
	}
}

int main()
{
	Node *path_list = build_path_list();

	if (path_list != NULL)
	{
		print_path_list(path_list);
		free_path_list(path_list);
	}

	return 0;
}
