//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Defining a struct for a node in our data structure
typedef struct Node {
   int data;
   struct Node* next;
} Node;

// Function to insert a new node at the beginning of the linked list
void insert(Node** head, int newData) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = newData;
   newNode->next = (*head);
   (*head) = newNode;
}

// Function to print the linked list
void printList(Node* node) {
   while (node != NULL) {
      printf("%d ", node->data);
      node = node->next;
   }
   printf("\n");
}

// Function to delete a node from the linked list
void deleteNode(Node** head, int key) {
   Node* temp = *head;
   Node* prev = NULL;
   if (temp != NULL && temp->data == key) {
      *head = temp->next;
      free(temp);
      return;
   }
   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL)
      return;
   prev->next = temp->next;
   free(temp);
}

int main() {
   Node* head = NULL;

   // Inserting some nodes into our data structure
   insert(&head, 12);
   insert(&head, 4);
   insert(&head, 3);
   insert(&head, 8);
   insert(&head, 17);

   printf("Linked list before deletion: ");
   printList(head);

   // Deleting a node from our data structure
   deleteNode(&head, 8);

   printf("Linked list after deletion: ");
   printList(head);

   return 0;
}