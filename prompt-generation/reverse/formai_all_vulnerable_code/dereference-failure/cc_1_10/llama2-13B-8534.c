//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new linked list
struct Node* newList(void) {
  struct Node* head = malloc(sizeof(struct Node));
  head->data = 0;
  head->next = NULL;
  return head;
}

// Function to insert an element into the linked list
void insert(struct Node** head_ref, int data) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to print the linked list
void print(struct Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

// Function to find the minimum element in the linked list
struct Node* min(struct Node* head) {
  struct Node* current = head;
  struct Node* previous = NULL;

  while (current != NULL) {
    if (previous == NULL || current->data < previous->data) {
      previous = current;
      current = current->next;
    } else {
      current = current->next;
    }
  }

  return previous;
}

int main() {
  struct Node* head = newList();

  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);

  print(head);

  struct Node* min_node = min(head);
  printf("Minimum element: %d\n", min_node->data);

  return 0;
}