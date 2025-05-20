//FormAI DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
   int data;
   struct Node *next;
} node;

void insertNode(node **head, int n) {
   node *newNode = (node*)malloc(sizeof(node));
   newNode->data = n;
   newNode->next = *head;
   *head = newNode;
}

void printList(node *head) {
   if(head==NULL) {
      printf("List is Empty!");
      return;
   }
   node *temp = head;
   while(temp!=NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
}

void deleteNode(node **head, int n) {
   if(*head==NULL) {
      printf("List is Empty!");
      return;
   }
   node *temp = *head;
   node *prev = NULL;
   while(temp!=NULL) {
      if(temp->data==n) {
         if(prev==NULL) {
            *head = temp->next;
            free(temp);
            return;
         }
         prev->next = temp->next;
         free(temp);
         return;
      }
      prev = temp;
      temp = temp->next;
   }
}

void reverseList(node **head){
   node *prev = NULL;
   node *current = *head;
   node *next = NULL;
   while(current!=NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }
   *head = prev;
}

void swapNodes(node **head, int x, int y) {
   if(x==y) return;
   node *prevX = NULL;
   node *currX = *head;
   while(currX && currX->data!=x) {
      prevX = currX;
      currX = currX->next;
   }
   node *prevY = NULL;
   node *currY = *head;
   while(currY && currY->data!=y) {
      prevY = currY;
      currY = currY->next;
   }
   if(currX==NULL || currY==NULL) return;
   if(prevX!=NULL) prevX->next = currY;
   else *head = currY;
   if(prevY!=NULL) prevY->next = currX;
   else *head = currX;
   node *temp = currY->next;
   currY->next = currX->next;
   currX->next = temp;
}

void shuffleList(node **head) {
   int n = 0;
   node *temp = *head;
   while(temp!=NULL) {
      n++;
      temp = temp->next;
   }
   srand(time(NULL));
   for(int i=n-1; i>0; i--) {
      int j = rand()%(i+1);
      node *node1 = *head;
      node *node2 = *head;
      for(int k=0; k<i; k++) node1=node1->next;
      for(int k=0; k<j; k++) node2=node2->next;
      int temp = node1->data;
      node1->data = node2->data;
      node2->data = temp;
   }
}

int main() {
   node *head = NULL;
   insertNode(&head, 10);
   insertNode(&head, 20);
   insertNode(&head, 30);
   insertNode(&head, 40);
   insertNode(&head, 50);
   printf("List before deletion: ");
   printList(head);
   deleteNode(&head, 30);
   printf("\nList after deletion: ");
   printList(head);
   printf("\nReversed List: ");
   reverseList(&head);
   printList(head);
   swapNodes(&head, 10, 50);
   printf("\nList after swapping nodes: ");
   printList(head);
   shuffleList(&head);
   printf("\nList after shuffling nodes: ");
   printList(head);
   return 0;
}