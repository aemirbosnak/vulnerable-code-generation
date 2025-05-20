//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void print_list(node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  // Create a linked list of the alphabet
  node *head = NULL;
  for (char c = 'A'; c <= 'Z'; c++) {
    node *new_node = malloc(sizeof(node));
    new_node->data = c;
    new_node->next = head;
    head = new_node;
  }

  // Print the linked list in reverse order
  printf("My love, let me serenade you with the alphabet in reverse:\n");
  print_list(head);

  // Create a linked list of your love's name
  char name[] = "Emily";
  node *name_head = NULL;
  for (int i = 0; name[i] != '\0'; i++) {
    node *new_node = malloc(sizeof(node));
    new_node->data = name[i];
    new_node->next = name_head;
    name_head = new_node;
  }

  // Print your love's name in a charming way
  printf("\nAnd now, my darling, let me spell your name in a way that will make your heart flutter:\n");
  node *current = name_head;
  while (current != NULL) {
    printf("%c", current->data);
    if (current->next != NULL) {
      printf(" - ");
    }
    current = current->next;
  }
  printf(".\n");

  // Free the memory allocated for the linked lists
  while (head != NULL) {
    node *next = head->next;
    free(head);
    head = next;
  }
  while (name_head != NULL) {
    node *next = name_head->next;
    free(name_head);
    name_head = next;
  }

  return 0;
}