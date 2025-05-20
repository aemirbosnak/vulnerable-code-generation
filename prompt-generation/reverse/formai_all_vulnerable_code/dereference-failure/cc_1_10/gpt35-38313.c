//FormAI DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct node {
   int val;
   struct node *next;
};

/* Function to insert a node at the beginning of a linked list */
void insertAtBeginning(struct node **head, int data) {
   // Allocate memory for a new node
   struct node *newNode = (struct node*) malloc(sizeof(struct node));

   // Set the value of the new node to the given data
   newNode->val = data;

   // Set the next pointer of the new node to the current head
   newNode->next = *head;

   // Set the head to be the new node
   *head = newNode;
}

/* Function to insert a node at the end of a linked list */
void insertAtEnd(struct node **head, int data) {
   // Allocate memory for a new node
   struct node *newNode = (struct node*) malloc(sizeof(struct node));

   // Set the value of the new node to the given data
   newNode->val = data;

   // Set the next pointer of the new node to NULL
   newNode->next = NULL;

   // If the list is empty, set the head to be the new node
   if (*head == NULL) {
      *head = newNode;
      return;
   }

   // Find the end of the list
   struct node *current = *head;
   while (current->next != NULL) {
      current = current->next;
   }

   // Set the next pointer of the last node to the new node
   current->next = newNode;
}

/* Function to delete the first occurrence of a given value in a linked list */
void deleteNode(struct node **head, int data) {
   // If the list is empty, do nothing
   if (*head == NULL) {
      return;
   }

   // If the first node is the one to be deleted, update the head
   if ((*head)->val == data) {
      struct node *temp = *head;
      *head = (*head)->next;
      free(temp);
      return;
   }

   // Find the node to be deleted
   struct node *current = *head;
   while (current->next != NULL && current->next->val != data) {
      current = current->next;
   }

   // If the node was not found, do nothing
   if (current->next == NULL) {
      return;
   }

   // Delete the node
   struct node *temp = current->next;
   current->next = current->next->next;
   free(temp);
}

/* Function to print all elements in a linked list */
void printList(struct node *head) {
   printf("[");
   while (head != NULL) {
      printf("%d", head->val);
      head = head->next;
      if (head != NULL) {
         printf(", ");
      }
   }
   printf("]\n");
}

int main() {
   // Create an empty linked list
   struct node *head = NULL;

   // Insert some nodes at the beginning
   insertAtBeginning(&head, 3);
   insertAtBeginning(&head, 2);
   insertAtBeginning(&head, 1);

   // Print the list
   printf("List after inserting 3 nodes at the beginning: ");
   printList(head);

   // Insert some nodes at the end
   insertAtEnd(&head, 4);
   insertAtEnd(&head, 5);

   // Print the list
   printf("List after inserting 2 nodes at the end: ");
   printList(head);

   // Delete nodes from the list
   deleteNode(&head, 1);
   deleteNode(&head, 3);

   // Print the list
   printf("List after deleting nodes with values 1 and 3: ");
   printList(head);

   // Free memory allocated for the list
   while (head != NULL) {
      struct node *temp = head;
      head = head->next;
      free(temp);
   }

   return 0;
}