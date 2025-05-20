//FormAI DATASET v1.0 Category: Linked list operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list
typedef struct node {
   int data;
   struct node *next;
} Node;

// Create a new node with the given data and return its pointer
Node *create_node(int data) {
   Node *new_node = (Node*) malloc(sizeof(Node));
   new_node->data = data;
   new_node->next = NULL;
   return new_node;
}

// Add a node with given data to the end of the linked list
void append_node(Node **head_ref, int data) {
   Node *new_node = create_node(data);
   Node *current = *head_ref;
   if (*head_ref == NULL) {
      *head_ref = new_node;
   } else {
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = new_node;
   }
}

// Add a node with given data to the start of the linked list
void prepend_node(Node **head_ref, int data) {
   Node *new_node = create_node(data);
   new_node->next = *head_ref;
   *head_ref = new_node;
}

// Insert a node with given data at the given position in the linked list
void insert_node(Node **head_ref, int data, int position) {
   if (position < 0) {
      printf("Invalid position.\n");
      return;
   }
   if (position == 0) {
      prepend_node(head_ref, data);
      return;
   }
   Node *new_node = create_node(data);
   Node *current = *head_ref;
   int i;
   for (i = 0; i < position - 1 && current->next != NULL; i++) {
      current = current->next;
   }
   if (i < position - 1) {
      printf("Position out of range.\n");
      free(new_node);
      return;
   }
   new_node->next = current->next;
   current->next = new_node;
}

// Remove the first occurrence of the given data from the linked list
void remove_node(Node **head_ref, int data) {
   Node *current = *head_ref;
   Node *prev = NULL;
   while (current != NULL && current->data != data) {
      prev = current;
      current = current->next;
   }
   if (current == NULL) {
      printf("Data not found.\n");
      return;
   }
   if (prev == NULL) {
      *head_ref = current->next;
   } else {
      prev->next = current->next;
   }
   free(current);
}

// Reverse the linked list
void reverse_list(Node **head_ref) {
   Node *current = *head_ref;
   Node *prev = NULL;
   Node *next = NULL;
   while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }
   *head_ref = prev;
}

// Print the linked list
void print_list(Node *head) {
   if (head == NULL) {
      printf("The list is empty.\n");
      return;
   }
   while (head != NULL) {
      printf("%d -> ", head->data);
      head = head->next;
   }
   printf("NULL\n");
}

int main() {
   Node *list = NULL;
   append_node(&list, 1);
   append_node(&list, 2);
   append_node(&list, 3);
   prepend_node(&list, 0);
   insert_node(&list, 4, 4);
   insert_node(&list, -1, -1);
   remove_node(&list, 3);
   reverse_list(&list);
   print_list(list);
   return 0;
}