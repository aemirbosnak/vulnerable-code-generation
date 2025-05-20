//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct node {
   int key;
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

/* Inserts a new node at the beginning of the list */
void insertFirst(int key, int data) {
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   temp->key = key;
   temp->data = data;
   temp->next = head;
   head = temp;
}

/* Inserts a new node at the end of the list */
void insertLast(int key, int data) {
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   temp->key = key;
   temp->data = data;
   
   if (head == NULL) {
      temp->next = NULL;
      head = temp;
      return;
   }
   
   current = head;
   
   while (current->next != NULL)
      current = current->next;
      
   current->next = temp;
   temp->next = NULL;
}

/* Prints the entire list */
void printList() {
   struct node *ptr = head;
   
   while (ptr != NULL) {
      printf("(%d, %d)\n",ptr->key, ptr->data);
      ptr = ptr->next;
   }
}

int main() {
   insertFirst(4, 5);
   insertFirst(3, 9);
   insertFirst(2, 17);
   insertFirst(1, 22);

   printf("Original List: ");
   
   printList();

   return 0;
}