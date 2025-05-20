//FormAI DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node structure
typedef struct Node {
  int val;
  struct Node* next;
} Node;

// Define the linked list data structure
typedef struct LinkedList {
  Node* head;
  int size;
} LinkedList;

// Function to create a new node with the specified value
Node* create_node(int val) {
  Node* node = malloc(sizeof(Node));
  node->val = val;
  node->next = NULL;
  return node;
}

// Function to insert a new node with the specified value at the end of the linked list
void insert_end(LinkedList* list, int val) {
  // Create a new node with the specified value
  Node* node = create_node(val);

  // Check if the linked list is empty
  if (list->head == NULL) {
    list->head = node;
  } else {
    // Traverse the linked list to find the last node
    Node* curr = list->head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = node;
  }
  list->size++;
}

// Function to print the contents of the linked list
void print_list(LinkedList* list) {
  Node* curr = list->head;
  printf("[");
  while (curr != NULL) {
    printf("%d", curr->val);
    curr = curr->next;
    if (curr != NULL) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main() {
  // Initialize a new linked list
  LinkedList* list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->size = 0;

  // Insert some values into the linked list
  insert_end(list, 1);
  insert_end(list, 2);
  insert_end(list, 3);

  // Print the contents of the linked list
  print_list(list);

  return 0;
}