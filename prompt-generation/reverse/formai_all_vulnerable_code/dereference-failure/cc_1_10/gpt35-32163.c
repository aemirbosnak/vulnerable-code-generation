//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head = NULL;

void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}

void delete(int key) {
   struct Node* temp = head, *prev;

   if (temp != NULL && temp->data == key) {
      head = temp->next;
      free(temp);
      return;
   }

   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL) return;

   prev->next = temp->next;
   free(temp);
}

void display() {
   struct Node* temp = head;

   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
}

int main() {
   insert(1);
   insert(2);
   insert(3);
   insert(4);

   printf("Linked list: ");
   display();

   delete(3);
   printf("\nLinked list after deleting an element: ");
   display();
   
   return 0;
}