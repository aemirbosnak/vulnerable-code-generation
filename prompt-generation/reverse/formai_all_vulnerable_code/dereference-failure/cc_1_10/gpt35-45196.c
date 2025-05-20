//FormAI DATASET v1.0 Category: Educational ; Style: accurate
/* 
   This program is a simple implementation of a linked list in C. 
   It allows the user to add and delete nodes as well as display the list. 

   Author: [Your Name]
   Date: [Current Date]
*/

#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a node */
struct node {
   int data;
   struct node *next;
};

/* Initialize pointers to the head and tail of the list */
struct node *head = NULL;
struct node *tail = NULL;

/* Function to add a node to the end of the list */
void append(int data) {
   struct node *new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = data;
   new_node->next = NULL;

   /* If the list is empty, the new node becomes the head */
   if (head == NULL) {
      head = new_node;
      tail = new_node;
   }
   /* Otherwise, add the new node to the end */
   else {
      tail->next = new_node;
      tail = new_node;
   }
}

/* Function to delete a node from the list */
void delete(int data) {
   struct node *current = head;
   struct node *previous = NULL;

   /* Traverse the list until the desired node is found */
   while (current != NULL && current->data != data) {
      previous = current;
      current = current->next;
   }

   /* If the node is not found, exit the function */
   if (current == NULL) {
      printf("Node not found.\n");
      return;
   }

   /* If the node is the head, update the head pointer */
   if (current == head) {
      head = head->next;
   }
   /* If the node is the tail, update the tail pointer */
   else if (current == tail) {
      tail = previous;
      tail->next = NULL;
   }
   /* If the node is in the middle, update the previous node's pointer */
   else {
      previous->next = current->next;
   }

   /* Free the memory allocated for the deleted node */
   free(current);
}

/* Function to print the contents of the list */
void print() {
   struct node *current = head;
   while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
   }
   printf("\n");
}

int main() {
   /* Add some nodes to the list */
   append(5);
   append(10);
   append(15);

   /* Display the list */
   printf("Original list: ");
   print();

   /* Delete the node with the value 10 */
   delete(10);

   /* Display the updated list */
   printf("Updated list: ");
   print();

   return 0;
}