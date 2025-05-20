//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
  struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void add(char *name, char *email) {
  node *new_node = malloc(sizeof(node));
  new_node->name = strdup(name);
  new_node->email = strdup(email);
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
}

void print_list() {
  node *current = head;
  while (current != NULL) {
    printf("%s <%s>\n", current->name, current->email);
    current = current->next;
  }
}

void free_list() {
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free(current->name);
    free(current->email);
    free(current);
    current = next;
  }
}

int main() {
  add("John Doe", "johndoe@example.com");
  add("Jane Doe", "janedoe@example.com");
  add("Peter Jones", "peterjones@example.com");

  print_list();

  free_list();

  return 0;
}