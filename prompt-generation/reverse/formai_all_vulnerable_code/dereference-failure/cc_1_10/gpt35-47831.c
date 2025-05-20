//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

// Creating Node structure

struct node {
   int data;
   struct node *next;
};

void main() {

   struct node *head = NULL;
   struct node *newnode = NULL;
   struct node *temp = NULL;

   // inserting elements in linked list
   
   newnode =(struct node*)malloc(sizeof(struct node));
   newnode->data = 10;
   newnode->next = NULL;
   head = newnode;

   newnode =(struct node*)malloc(sizeof(struct node));
   newnode->data = 20;
   newnode->next = NULL;
   head->next = newnode;

   newnode =(struct node*)malloc(sizeof(struct node));
   newnode->data = 30;
   newnode->next = NULL;
   head->next->next = newnode;
   
   // Traversing through linked list
   
   printf("\nLinked list elements are: ");
   temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   
   // Inserting element at the beginning
   
   newnode =(struct node*)malloc(sizeof(struct node));
   newnode->data = 5;
   newnode->next = NULL;
   head = newnode;
   head->next = temp;
   
   // Traversing through linked list
   
   printf("\nLinked list elements after inserting at the beginning are: ");
   temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }

   // inserting element at the end
   
   newnode =(struct node*)malloc(sizeof(struct node));
   newnode->data = 40;
   newnode->next = NULL;
   temp = head;
   while (temp->next != NULL) {
      temp = temp->next;
   }
   temp->next = newnode;
  
   // Traversing through linked list
   
   printf("\nLinked list elements after inserting at the end are: ");
   temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   
   // Deleting first node
   
   temp = head;
   head = head->next;
   free(temp);

   // Traversing through linked list
   
   printf("\nLinked list elements after deleting first element are: ");
   temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   
   // Deleting last node
   
   struct node *prev = NULL;
   temp = head;
   while (temp->next != NULL) {
      prev = temp;
      temp = temp->next;
   }
   prev->next = NULL;
   free(temp);

   // Traversing through linked list
   
   printf("\nLinked list elements after deleting last element are: ");
   temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
}