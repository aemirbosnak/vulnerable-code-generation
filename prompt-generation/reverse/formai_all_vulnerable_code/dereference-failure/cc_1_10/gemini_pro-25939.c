//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char *value;
  struct node *next;
};

struct node *parse(char *input) {
  struct node *head = NULL;
  struct node *current = NULL;
  char *token = strtok(input, " ");

  while (token != NULL) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = token;
    new_node->next = NULL;

    if (head == NULL) {
      head = new_node;
    } else {
      current->next = new_node;
    }

    current = new_node;
    token = strtok(NULL, " ");
  }

  return head;
}

void print_list(struct node *head) {
  struct node *current = head;

  while (current != NULL) {
    printf("%s ", current->value);
    current = current->next;
  }

  printf("\n");
}

int main() {
  char input[] = "Hello world this is a test";
  struct node *head = parse(input);

  print_list(head);

  return 0;
}