//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: retro
// The C Searching Algorithm

#include <stdio.h>
#include <stdlib.h>

// Define a structure to store data
typedef struct node {
  int data;
  struct node* next;
} node;

// Function to search for a node in a linked list
node* search(node* head, int target) {
  // Traverse the list until the target is found or the end of the list is reached
  while (head) {
    if (head->data == target) {
      return head;
    } else if (head->data < target) {
      head = head->next;
    } else {
      return NULL;
    }
  }

  // If the target is not found, return NULL
  return NULL;
}

// Main function
int main() {
  // Create a linked list
  node* head = NULL;
  head = malloc(sizeof(node));
  head->data = 10;
  head->next = malloc(sizeof(node));
  head->next->data = 20;
  head->next->next = malloc(sizeof(node));
  head->next->next->data = 30;

  // Search for a node in the list
  node* result = search(head, 20);

  // If the node is found, print its data
  if (result) {
    printf("The data of the node is: %d\n", result->data);
  } else {
    printf("The target node is not found.\n");
  }

  return 0;
}