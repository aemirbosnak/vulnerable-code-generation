//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>

// A node in a linked list
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Create a new node
Node* createNode(int data) {
  Node *node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Insert a node at the beginning of a linked list
Node* insertAtBeginning(Node *head, int data) {
  Node *newNode = createNode(data);
  newNode->next = head;
  return newNode;
}

// Insert a node at the end of a linked list
Node* insertAtEnd(Node *head, int data) {
  Node *newNode = createNode(data);
  if (head == NULL) {
    return newNode;
  }

  Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
  return head;
}

// Insert a node after a given node in a linked list
Node* insertAfter(Node *head, int data, int afterData) {
  Node *newNode = createNode(data);

  Node *current = head;
  while (current != NULL) {
    if (current->data == afterData) {
      newNode->next = current->next;
      current->next = newNode;
      return head;
    }

    current = current->next;
  }

  return head;
}

// Delete a node from a linked list
Node* deleteNode(Node *head, int data) {
  if (head == NULL) {
    return NULL;
  }

  if (head->data == data) {
    Node *newHead = head->next;
    free(head);
    return newHead;
  }

  Node *current = head;
  while (current->next != NULL) {
    if (current->next->data == data) {
      Node *next = current->next->next;
      free(current->next);
      current->next = next;
      return head;
    }

    current = current->next;
  }

  return head;
}

// Reverse a linked list
Node* reverseList(Node *head) {
  if (head == NULL) {
    return NULL;
  }

  if (head->next == NULL) {
    return head;
  }

  Node *newHead = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

// Print a linked list
void printList(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

// Driver code
int main() {
  Node *head = NULL;

  head = insertAtBeginning(head, 1);
  head = insertAtEnd(head, 2);
  head = insertAtEnd(head, 3);
  head = insertAfter(head, 4, 2);
  head = deleteNode(head, 3);
  head = reverseList(head);

  printList(head);

  return 0;
}