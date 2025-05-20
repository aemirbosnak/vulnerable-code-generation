//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure for a linked list
typedef struct node {
   int data;
   struct node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to print a linked list
void printList(Node* head) {
   Node* temp = head;
   while (temp!= NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
   Node* prev = NULL;
   Node* curr = head;
   while (curr!= NULL) {
      Node* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }
   return prev;
}

// Function to sort a linked list using insertion sort
Node* sortList(Node* head) {
   Node* curr = head;
   while (curr!= NULL) {
      Node* next = curr->next;
      Node* prev = NULL;
      while (prev!= NULL && curr->data > prev->data) {
         curr = prev;
      }
      curr->next = next;
      prev = curr;
      curr = next;
   }
   return head;
}

int main() {
   Node* head = NULL;
   head = createNode(5);
   head->next = createNode(3);
   head->next->next = createNode(7);
   head->next->next->next = createNode(1);
   head->next->next->next->next = createNode(9);

   printf("Original list:\n");
   printList(head);

   head = reverseList(head);
   printf("Reversed list:\n");
   printList(head);

   head = sortList(head);
   printf("Sorted list:\n");
   printList(head);

   return 0;
}