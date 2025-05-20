//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to push an element onto the list
void push(struct Node** head_ref, int data) {
  struct Node* new_node = newNode(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to pop an element off the list
int pop(struct Node** head_ref) {
  int data = (*head_ref)->data;
  struct Node* temp = *head_ref;
  *head_ref = temp->next;
  free(temp);
  return data;
}

// Function to traverse the list and print out all the elements
void traverse(struct Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

// Function to find the middle element of the list
int findMiddle(struct Node* head) {
  int mid = 0;
  int count = 0;
  struct Node* current = head;

  while (current != NULL) {
    count++;
    if (count == head->next->next->next->next->next->next->next->next->next) {
      mid = current->data;
      break;
    }
    current = current->next;
  }

  return mid;
}

int main() {
  struct Node* head = NULL;

  // Create a list with some elements
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);

  // Print out the list
  traverse(head);

  // Find the middle element of the list
  int mid = findMiddle(head);
  printf("The middle element of the list is: %d\n", mid);

  // Pop an element off the list
  int popped = pop(&head);
  printf("Popped element: %d\n", popped);

  // Add a new element to the list using the 'magic' function
  struct Node* new_node = newNode(10);
  push(&head, new_node);

  // Traverse the list again to make sure everything is still in order
  traverse(head);

  return 0;
}