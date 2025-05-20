//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdlib.h>
#include <stdio.h>

// Visionary Data Structure: Node
typedef struct node {
  int data;
  struct node *next;
} Node;

// Visionary Function: Node Creation
Node* createNode(int data) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Visionary Function: Linked List Creation
Node* createLinkedList() {
  return NULL;
}

// Visionary Function: Linked List Insertion
void insertIntoLinkedList(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// Visionary Function: Linked List Deletion
void deleteFromLinkedList(Node **head, int data) {
  if (*head == NULL) {
    return;
  } else if ((*head)->data == data) {
    *head = (*head)->next;
  } else {
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != data) {
      prev = temp;
      temp = temp->next;
    }
    if (temp != NULL) {
      prev->next = temp->next;
      free(temp);
    }
  }
}

// Visionary Function: Linked List Traversal
void traverseLinkedList(Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

// Visionary Program Execution
int main() {
  Node* head = createLinkedList();
  insertIntoLinkedList(&head, 10);
  insertIntoLinkedList(&head, 20);
  insertIntoLinkedList(&head, 30);
  insertIntoLinkedList(&head, 40);
  insertIntoLinkedList(&head, 50);
  printf("\nLinked List Creation:");
  traverseLinkedList(head);
  deleteFromLinkedList(&head, 30);
  deleteFromLinkedList(&head, 50);
  printf("\nLinked List after Deletions:");
  traverseLinkedList(head);
  return 0;
}