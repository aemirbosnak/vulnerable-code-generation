//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char *data;
  struct node *next;
};

typedef struct node *node_ptr;

node_ptr create_node(char *data) {
  node_ptr new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void push(node_ptr *head, char *data) {
  node_ptr new_node = create_node(data);
  if (*head == NULL)
    *head = new_node;
  else {
    new_node->next = *head;
    *head = new_node;
  }
}

char *pop(node_ptr *head) {
  if (*head == NULL)
    return NULL;
  else {
    char *data = (*head)->data;
    node_ptr temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
  }
}

void print_stack(node_ptr head) {
  while (head != NULL) {
    printf("%s\n", head->data);
    head = head->next;
  }
}

int main() {
  node_ptr stack = NULL;
  char *line;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, stdin)) != -1) {
    line[strlen(line) - 1] = '\0';
    push(&stack, line);
  }

  print_stack(stack);

  return 0;
}