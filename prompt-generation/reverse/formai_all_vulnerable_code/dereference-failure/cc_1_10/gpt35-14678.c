//FormAI DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for our linked list node */
struct node {
   int data;
   struct node *next;
};

/* Declare our functions */
void insertAtBeginning(struct node **head, int newData);
void insertAtEnd(struct node **head, int newData);
void deleteNode(struct node **head, int key);
void printList(struct node *head);

/* Main Function */
int main() {

   /* Initialize the head node */
   struct node *head = NULL;

   /* Add some data to the beginning of the list */
   insertAtBeginning(&head, 6);
   insertAtBeginning(&head, 4);
   insertAtBeginning(&head, 2);

   /* Add some data to the end of the list */
   insertAtEnd(&head, 8);
   insertAtEnd(&head, 10);
   insertAtEnd(&head, 12);

   /* Print the list */
   printf("Linked List: ");
   printList(head);

   /* Delete a node from the list */
   deleteNode(&head, 8);

   /* Print the modified list */
   printf("\nLinked List after deletion: ");
   printList(head);

   /* Exit the program */
   return 0;
}

/* Function to add a new node to the beginning of the list */
void insertAtBeginning(struct node **head, int newData) {

   /* Allocate memory for a new node */
   struct node *newNode = (struct node*) malloc(sizeof(struct node));

   /* Put the data into the new node */
   newNode->data = newData;

   /* Link the new node to the beginning of the list */
   newNode->next = *head;

   /* Set the head to the new node */
   *head = newNode;
}

/* Function to add a new node to the end of the list */
void insertAtEnd(struct node **head, int newData) {

   /* Allocate memory for a new node */
   struct node *newNode = (struct node*) malloc(sizeof(struct node));

   /* Put the data into the new node */
   newNode->data = newData;

   /* Set the next of the new node to NULL */
   newNode->next = NULL;

   /* Check if the list is empty */
   if (*head == NULL) {
      *head = newNode;
      return;
   }

   /* Traverse to the end of the list */
   struct node *temp = *head;
   while (temp->next != NULL) {
      temp = temp->next;
   }

   /* Link the new node to the end of the list */
   temp->next = newNode;
}

/* Function to delete a node from the list */
void deleteNode(struct node **head, int key) {

   /* Check if the list is empty */
   if (*head == NULL) {
      return;
   }

   /* Check if the key is in the head node */
   if ((*head)->data == key) {
      (*head) = (*head)->next;
      return;
   }

   /* Traverse the list to find the node to delete */
   struct node *temp = *head;
   while (temp->next != NULL && temp->next->data != key) {
      temp = temp->next;
   }

   /* Check if the node was not found */
   if (temp->next == NULL) {
      printf("Element not found in the linked list.\n");
      return;
   }

   /* Delete the node */
   struct node *nextNode = temp->next->next;
   free(temp->next);
   temp->next = nextNode;
}

/* Function to print the list */
void printList(struct node *head) {

   /* Traverse the list and print each node */
   while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }
}