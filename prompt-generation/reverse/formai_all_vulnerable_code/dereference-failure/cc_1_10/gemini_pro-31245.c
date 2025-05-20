//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void add_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void print_list() {
  struct node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void delete_node(int data) {
  struct node *current = head;
  struct node *prev = NULL;
  while (current != NULL) {
    if (current->data == data) {
      if (prev == NULL) {
        head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      break;
    }
    prev = current;
    current = current->next;
  }
}

int main() {
  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int data;
    printf("Enter the data for node %d: ", i + 1);
    scanf("%d", &data);
    add_node(data);
  }
  printf("The linked list is: ");
  print_list();
  int data;
  printf("Enter the data of the node to be deleted: ");
  scanf("%d", &data);
  delete_node(data);
  printf("The linked list after deletion is: ");
  print_list();
  return 0;
}