//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
} Node;

Node *head;

void insert(int num) {
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->data = num;
   newNode->next = head;
   head = newNode;
}

void delete(int num) {
   Node *temp = head;
   Node *prev = NULL;
   while (temp != NULL && temp->data != num) {
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL) {
      printf("\nError: %d not found to delete.", num);
      return;
   }
   if (prev == NULL) {
      head = temp->next;
   } else {
      prev->next = temp->next;
   }
   free(temp);
}

void printList() {
   Node *temp = head;
   printf("\nLinked List: ");
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main() {
   head = NULL;
   insert(5);
   insert(4);
   insert(3);
   insert(2);
   insert(1);
   printf("Initial ");
   printList();
   printf("\nDeleting 3\n");
   delete(3);
   printList();
   printf("\nDeleting 6\n");
   delete(6);
   printList();
   printf("\nInserting 10 at beginning\n");
   insert(10);
   printList();
   return 0;
}