//FormAI DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

/* Define the structure of linked list nodes */
typedef struct node {
   int data;          // Data of the node
   struct node *next; // Pointer to the next node
} Node;

/* Linked list operations */
Node *createNode(int data) {
   Node *newNode = malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

void insertNode(Node **head, int data) {
   Node *newNode = createNode(data);
   newNode->next = *head;
   *head = newNode;
}

void deleteNode(Node **head, int data) {
   Node *currentNode = *head;
   Node *previousNode = NULL;

   while (currentNode != NULL && currentNode->data != data) {
      previousNode = currentNode;
      currentNode = currentNode->next;
   }

   if (currentNode == NULL) return;

   if (previousNode == NULL) {
      *head = currentNode->next;
   } else {
      previousNode->next = currentNode->next;
   }

   free(currentNode);
}

void printList(Node *head) {
   if (head == NULL) {
      printf("List is empty.\n");
      return;
   }

   while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }

   printf("\n");
}

int main() {
   Node *head = NULL;

   insertNode(&head, 10);
   insertNode(&head, 20);
   insertNode(&head, 30);
   insertNode(&head, 40);

   printf("Linked list before deletion: ");
   printList(head);

   deleteNode(&head, 30);

   printf("Linked list after deletion: ");
   printList(head);

   return 0;
}