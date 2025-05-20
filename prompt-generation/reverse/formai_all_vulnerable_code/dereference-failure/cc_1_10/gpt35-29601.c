//FormAI DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;

// Function to insert a new node at the beginning of the list
void insertAtBeginning(int data) {
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = head;
   head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(int data) {
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = NULL;
   if(head == NULL) {
      head = newNode;
      return;
   }
   struct node *temp = head;
   while(temp->next != NULL) {
      temp = temp->next;
   }
   temp->next = newNode;
   return;
}

// Function to delete the first node of the list
void deleteFirstNode() {
   if(head == NULL) {
      printf("List is already empty!");
      return;
   }
   struct node *temp = head;
   head = head->next;
   free(temp);
   printf("First node deleted!");
   return;
}

// Function to delete the last node of the list
void deleteLastNode() {
   if(head == NULL) {
      printf("List is already empty!");
      return;
   }
   if(head->next == NULL) {
      head = NULL;
      return;
   }
   struct node *temp = head;
   while(temp->next->next != NULL) {
      temp = temp->next;
   }
   free(temp->next);
   temp->next = NULL;
   printf("Last node deleted!");
   return;
}

// Function to display the list
void displayList() {
   struct node *temp = head;
   if(head == NULL) {
      printf("List is empty!");
      return;
   }
   while(temp != NULL) {
      printf("%d  ",temp->data);
      temp = temp->next;
   }
   return;
}

int main() {
   // Inserting nodes at the beginning
   insertAtBeginning(5);
   insertAtBeginning(10);
   insertAtBeginning(15);
   printf("List after inserting nodes at the beginning: ");
   displayList();
   
   // Inserting nodes at the end
   insertAtEnd(20);
   insertAtEnd(30);
   insertAtEnd(40);
   printf("\nList after inserting nodes at the end: ");
   displayList();
   
   // Deleting the first node
   deleteFirstNode();
   printf("\nList after deleting first node: ");
   displayList();
   
   // Deleting the last node
   deleteLastNode();
   printf("\nList after deleting last node: ");
   displayList();

   return 0;
}