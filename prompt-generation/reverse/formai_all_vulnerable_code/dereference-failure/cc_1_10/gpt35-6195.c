//FormAI DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int data;
   struct node *next;
} node;

void addNodeToEnd(node **head, int data) {
   node *newNode = (node*)malloc(sizeof(node));
   newNode->data = data;
   newNode->next = NULL;
   if (*head == NULL) {
      *head = newNode;
      return;
   }
   node *ptr = *head;
   while (ptr->next != NULL) {
      ptr = ptr->next;
   }
   ptr->next = newNode;
}

void printList(node *head) {
   while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }
   printf("\n");
}

void createIndex(node *head, int *index) {
   int i = 0;
   while (head != NULL) {
      index[head->data] = i;
      i++;
      head = head->next;
   }
}

int main() {
   node *head = NULL;
   addNodeToEnd(&head, 5);
   addNodeToEnd(&head, 3);
   addNodeToEnd(&head, 7);
   addNodeToEnd(&head, 1);
   addNodeToEnd(&head, 9);
   addNodeToEnd(&head, 2);
   addNodeToEnd(&head, 4);
   addNodeToEnd(&head, 6);
   addNodeToEnd(&head, 8);
   printf("List before sorting: ");
   printList(head);

   int index[10] = { 0 };
   createIndex(head, index);

   for (int i = 0; i < 10; i++) {
      if (index[i] != 0) {
         printf("Value: %d\tIndex: %d\n", i, index[i]);
      }
   }

   return 0;
}