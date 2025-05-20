//FormAI DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insert(struct Node** head, int data) {
   struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

   newNode->data  = data;
   newNode->next = (*head);

   (*head) = newNode;
}

// Function to display the linked list
void display(struct Node* head) {
   struct Node* ptr = head;
   while (ptr != NULL) {
      printf("%d -> ", ptr->data);
      ptr = ptr->next;
   }
   printf("NULL\n");
}

// Function to delete the entire linked list
void deleteList(struct Node** head) {
   struct Node* current = *head;
   struct Node* next;

   while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
   }

   *head = NULL;
}

int main() {
   struct Node* head = NULL;

   insert(&head, 1);
   insert(&head, 2);
   insert(&head, 3);
   insert(&head, 4);

   printf("Linked List: ");
   display(head);

   deleteList(&head);

   printf("Linked list deleted successfully");

   return 0;
}