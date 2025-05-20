//FormAI DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Declare a struct for a node that contains an integer value and a pointer to the next node
struct Node {
  int data;
  struct Node* next;
};

// Declare a struct for the linked list that contains a pointer to the head node
struct LinkedList {
  struct Node* head;
};

// Function to create a new node with given data and return its address
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertNodeAtBeginning(struct LinkedList* ll, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = ll->head;
  ll->head = newNode;
}

// Function to insert a node at the end of the linked list
void insertNodeAtEnd(struct LinkedList* ll, int data) {
  struct Node* newNode = createNode(data);
  if (ll->head == NULL) {
    ll->head = newNode;
    return;
  }
  struct Node* current = ll->head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// Function to delete a node with the given data from the linked list
void deleteNode(struct LinkedList* ll, int data) {
  if (ll->head == NULL) {
    return;
  }
  if (ll->head->data == data) {
    struct Node* temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
    return;
  }
  struct Node* current = ll->head;
  while (current->next != NULL && current->next->data != data) {
    current = current->next;
  }
  if (current->next != NULL) {
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
  }
}

// Function to print the contents of the linked list
void printLinkedList(struct LinkedList* ll) {
  struct Node* current = ll->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Main function to test the linked list operations
int main() {
  struct LinkedList ll;
  ll.head = NULL;

  // Insert nodes at the beginning of the linked list
  insertNodeAtBeginning(&ll, 3);
  insertNodeAtBeginning(&ll, 2);
  insertNodeAtBeginning(&ll, 1);
  printf("Linked List after inserting nodes at the beginning: ");
  printLinkedList(&ll);

  // Insert nodes at the end of the linked list
  insertNodeAtEnd(&ll, 4);
  insertNodeAtEnd(&ll, 5);
  printf("Linked List after inserting nodes at the end: ");
  printLinkedList(&ll);

  // Delete a node from the linked list
  deleteNode(&ll, 3);
  printf("Linked List after deleting node with data 3: ");
  printLinkedList(&ll);

  return 0;
}