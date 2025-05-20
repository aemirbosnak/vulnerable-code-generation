//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

typedef struct node NODE;

NODE* createNode(int value) {
   NODE* newNode = malloc(sizeof(NODE));
   newNode->data = value;
   newNode->next = NULL;
   return newNode;
}

NODE* insertNode(NODE* head, NODE* nodeToInsert) {
   if(head == NULL) {
      head = nodeToInsert;
   } else {
      NODE* currentNode = head;
      while(currentNode->next != NULL) {
         currentNode = currentNode->next;
      }
      currentNode->next = nodeToInsert;
   }
   return head;
}

void displayList(NODE* head) {
   NODE* temp = head;
   printf("List: ");
   while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
}

int main() {
   NODE* head = NULL;
   NODE* node1 = createNode(10);
   NODE* node2 = createNode(9);
   NODE* node3 = createNode(8);
   NODE* node4 = createNode(7);
   NODE* node5 = createNode(6);
   NODE* node6 = createNode(5);
   NODE* node7 = createNode(4);
   NODE* node8 = createNode(3);
   NODE* node9 = createNode(2);
   NODE* node10 = createNode(1);

   head = insertNode(head, node1);
   head = insertNode(head, node2);
   head = insertNode(head, node3);
   head = insertNode(head, node4);
   head = insertNode(head, node5);
   head = insertNode(head, node6);
   head = insertNode(head, node7);
   head = insertNode(head, node8);
   head = insertNode(head, node9);
   head = insertNode(head, node10);

   displayList(head);
   return 0;
}