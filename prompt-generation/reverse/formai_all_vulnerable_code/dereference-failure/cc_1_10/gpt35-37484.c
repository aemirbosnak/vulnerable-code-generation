//FormAI DATASET v1.0 Category: Data structures visualization ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node* next;
};

struct node* createNode(int value) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->data = value;
   newNode->next = NULL;
   return newNode;
}

void insertAtBeginning(struct node** head, int value) {
   struct node* newNode = createNode(value);

   if (*head == NULL)
      *head = newNode;
   else {
      newNode->next = *head;
      *head = newNode;
   }
}

void insertAtEnd(struct node** head, int value) {
   struct node* newNode = createNode(value);

   if (*head == NULL)
      *head = newNode;
   else {

      struct node* temp = *head;

      while (temp->next != NULL)
         temp = temp->next;

      temp->next = newNode;
   }
}

void delete(struct node** head, int value) {
   struct node* temp = *head;
   struct node* prev = NULL;

   while (temp != NULL && temp->data != value) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL)
      return;

   if (prev == NULL)
      *head = temp->next;
   else
      prev->next = temp->next;

   free(temp);
}

void display(struct node* head) {
   while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }
}

int main() {
   struct node* head = NULL;
   insertAtBeginning(&head, 6);
   insertAtBeginning(&head, 4);
   insertAtEnd(&head, 8);
   insertAtEnd(&head, 7);
   delete(&head, 4);
   display(head);
   return 0;
}