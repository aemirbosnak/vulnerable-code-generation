//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {  // Define Node data structure
  int value;  // Node value, assuming integers for simplicity
  struct Node* next;  // Pointer to the next Node in the linked list
} Node;

void printLinkedList(Node* head) {  // Function to print the linked list starting from the head node
  printf("[ ");
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("]\n");
}

int main() {
  Node* head = NULL;  // Initialize head node
  Node* second = NULL;  // Initialize second node
  Node* third = NULL;  // Initialize third node

  // Allocate memory for the nodes
  head = (Node*)malloc(sizeof(Node));
  second = (Node*)malloc(sizeof(Node));
  third = (Node*)malloc(sizeof(Node));

  // Assign values to the nodes and set their next pointers
  head->value = 1;
  head->next = second;

  second->value = 2;
  second->next = third;

  third->value = 3;
  third->next = NULL;

  // Print the initial linked list
  printf("Initial linked list:\n");
  printLinkedList(head);
  printf("\n");

  // Insert a new node with value 4 between the second and third nodes
  printf("Inserting a new node with value 4...\n");
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value = 4;
  new_node->next = third;
  second->next = new_node;

  // Print the modified linked list
  printf("Modified linked list:\n");
  printLinkedList(head);
  printf("\n");

  // Remove the second node from the linked list
  printf("Removing the second node...\n");
  head->next = third;

  // Print the modified linked list
  printf("Modified linked list:\n");
  printLinkedList(head);
  printf("\n");

  // Free the memory allocated for the nodes
  free(head);
  free(second);
  free(third);

  return 0;
}