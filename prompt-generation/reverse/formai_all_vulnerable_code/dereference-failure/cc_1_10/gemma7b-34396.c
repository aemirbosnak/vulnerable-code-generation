//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct Node {
  char **lines;
  int size;
  struct Node *next;
} Node;

void insert_line(Node *node, char *line)
{
  node->lines = realloc(node->lines, (node->size + 1) * sizeof(char *));
  node->lines[node->size++] = line;
}

int main()
{
  Node *head = NULL;
  char **lines = NULL;
  int i = 0;

  // Allocate memory for the first node
  head = malloc(sizeof(Node));
  head->lines = malloc(MAX_LINES * sizeof(char *));
  head->size = 0;
  head->next = NULL;

  // Get the number of lines from the user
  printf("Enter the number of lines: ");
  scanf("%d", &i);

  // Allocate memory for the lines
  lines = malloc(i * sizeof(char *));

  // Get the lines from the user
  printf("Enter the lines: ");
  for (int j = 0; j < i; j++)
  {
    lines[j] = malloc(200 * sizeof(char));
    scanf("%[^\n]%*c", lines[j]);
  }

  // Insert the lines into the linked list
  for (int j = 0; j < i; j++)
  {
    insert_line(head, lines[j]);
  }

  // Print the lines from the linked list
  for (Node *node = head; node; node = node->next)
  {
    for (int j = 0; j < node->size; j++)
    {
      printf("%s\n", node->lines[j]);
    }
  }

  // Free the memory
  for (int j = 0; j < i; j++)
  {
    free(lines[j]);
  }
  free(lines);
  free(head);

  return 0;
}