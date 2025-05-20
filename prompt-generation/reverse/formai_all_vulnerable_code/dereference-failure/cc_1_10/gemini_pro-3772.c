//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void delete(int data) {
  struct node *current_node = head;
  struct node *previous_node = NULL;

  while (current_node != NULL) {
    if (current_node->data == data) {
      if (previous_node == NULL) {
        head = current_node->next;
      } else {
        previous_node->next = current_node->next;
      }
      free(current_node);
      return;
    }

    previous_node = current_node;
    current_node = current_node->next;
  }
}

void print() {
  struct node *current_node = head;

  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }

  printf("\n");
}

int main() {
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);

  print(); // 5 4 3 2 1

  delete(3);

  print(); // 5 4 2 1

  return 0;
}