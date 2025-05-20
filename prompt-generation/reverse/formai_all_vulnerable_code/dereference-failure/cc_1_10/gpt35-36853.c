//FormAI DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
} Node;

Node *createNode(int data) {
   Node *newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

Node *insertAtBeginning(Node *head, int data) {
   Node *newNode = createNode(data);
   if(head == NULL) {
      head = newNode;
   }
   else {
      newNode->next = head;
      head = newNode;
   }
   return head;
}

Node *insertAtEnd(Node *head, int data) {
   Node *newNode = createNode(data);
   if(head == NULL) {
      head = newNode;
   }
   else {
      Node *temp = head;
      while(temp->next != NULL) {
         temp = temp->next;
      }
      temp->next = newNode;
   }
   return head;
}

void displayList(Node *head) {
   if(head == NULL) {
      printf("List is empty\n");
   }
   else {
      Node *temp = head;
      while(temp != NULL) {
         printf("%d -> ", temp->data);
         temp = temp->next;
      }
      printf("NULL\n");
   }
}

int main() {
   Node *head = NULL;
   head = insertAtBeginning(head, 10);
   head = insertAtBeginning(head, 20);
   head = insertAtEnd(head, 30);
   displayList(head);
   return 0;
}