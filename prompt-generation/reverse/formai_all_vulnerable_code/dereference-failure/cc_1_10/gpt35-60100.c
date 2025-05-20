//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
} Node;

Node* createNode(int value) {
   Node* newNode = (Node*) malloc(sizeof(Node));
   newNode->data = value;
   newNode->next = NULL;
   return newNode;
}

void insertAfter(Node* prev, int value) {
   if (prev == NULL) {
      return;
   }
   Node* newNode = createNode(value);
   newNode->next = prev->next;
   prev->next = newNode;
}

void insertAtBeginning(Node** headRef, int value) {
   Node* newNode = createNode(value);
   newNode->next = *headRef;
   *headRef = newNode;
}

void insertAtEnd(Node** headRef, int value) {
   Node* newNode = createNode(value);
   if (*headRef == NULL) {
      *headRef = newNode;
      return;
   }
   Node* current = *headRef;
   while (current->next != NULL) {
      current = current->next;
   }
   current->next = newNode;
}

void deleteNode(Node** headRef, int value) {
   Node* current = *headRef;
   Node* previous = NULL;
   while (current != NULL && current->data != value) {
      previous = current;
      current = current->next;
   }
   if (current == NULL) {
      return;
   }
   if (previous == NULL) {
      *headRef = current->next;
   }
   else {
      previous->next = current->next;
   }
   free(current);
}

void display(Node* head) {
   while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }
}

int main() {
   Node* head = NULL;
   insertAtBeginning(&head, 10);
   insertAtEnd(&head, 20);
   insertAfter(head->next, 30);
   display(head);
   deleteNode(&head, 20);
   printf("\nLinked List after deletion: ");
   display(head);
   return 0;
}