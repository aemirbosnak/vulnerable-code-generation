//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
/* The Knuthian Data Recovery Tool */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node_t;

/* Push a new element onto the stack. */
void push(node_t **head, char *data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

/* Pop an element from the stack. */
char *pop(node_t **head) {
  if (*head == NULL) {
    return NULL;
  }
  char *data = (*head)->data;
  node_t *next = (*head)->next;
  free(*head);
  *head = next;
  return data;
}

/* Recover data from a damaged file. */
void recover(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("fopen");
    return;
  }
  node_t *stack = NULL;
  char line[1024];
  while (fgets(line, sizeof(line), file) != NULL) {
    char *data = strdup(line);
    push(&stack, data);
  }
  fclose(file);
  while (stack != NULL) {
    char *data = pop(&stack);
    printf("%s", data);
    free(data);
  }
}

/* Main entry point. */
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return EXIT_FAILURE;
  }
  recover(argv[1]);
  return EXIT_SUCCESS;
}