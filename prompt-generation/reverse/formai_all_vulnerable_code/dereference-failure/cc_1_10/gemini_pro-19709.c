//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
struct node {
   int data;
   struct node *next;
};

// Create a new node
struct node* create_node(int data) {
   struct node *new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = data;
   new_node->next = NULL;
   return new_node;
}

// Insert a new node at the beginning of a linked list
struct node* insert_at_beginning(struct node *head, int data) {
   struct node *new_node = create_node(data);
   new_node->next = head;
   return new_node;
}

// Insert a new node at the end of a linked list
struct node* insert_at_end(struct node *head, int data) {
   struct node *new_node = create_node(data);
   if (head == NULL) {
      return new_node;
   }
   struct node *current_node = head;
   while (current_node->next != NULL) {
      current_node = current_node->next;
   }
   current_node->next = new_node;
   return head;
}

// Insert a new node at a specific position in a linked list
struct node* insert_at_position(struct node *head, int data, int position) {
   struct node *new_node = create_node(data);
   if (position == 0) {
      return insert_at_beginning(head, data);
   }
   struct node *current_node = head;
   int i = 0;
   while (current_node->next != NULL && i < position - 1) {
      current_node = current_node->next;
      i++;
   }
   if (i == position - 1) {
      new_node->next = current_node->next;
      current_node->next = new_node;
      return head;
   }
   return head;
}

// Delete a node from the beginning of a linked list
struct node* delete_from_beginning(struct node *head) {
   if (head == NULL) {
      return NULL;
   }
   struct node *new_head = head->next;
   free(head);
   return new_head;
}

// Delete a node from the end of a linked list
struct node* delete_from_end(struct node *head) {
   if (head == NULL) {
      return NULL;
   }
   if (head->next == NULL) {
      free(head);
      return NULL;
   }
   struct node *current_node = head;
   while (current_node->next->next != NULL) {
      current_node = current_node->next;
   }
   free(current_node->next);
   current_node->next = NULL;
   return head;
}

// Delete a node from a specific position in a linked list
struct node* delete_from_position(struct node *head, int position) {
   if (position == 0) {
      return delete_from_beginning(head);
   }
   struct node *current_node = head;
   int i = 0;
   while (current_node->next != NULL && i < position - 1) {
      current_node = current_node->next;
      i++;
   }
   if (i == position - 1) {
      struct node *new_next = current_node->next->next;
      free(current_node->next);
      current_node->next = new_next;
      return head;
   }
   return head;
}

// Print a linked list
void print_linked_list(struct node *head) {
   struct node *current_node = head;
   while (current_node != NULL) {
      printf("%d ", current_node->data);
      current_node = current_node->next;
   }
   printf("\n");
}

// Main function
int main() {
   // Create a linked list
   struct node *head = NULL;
   head = insert_at_beginning(head, 10);
   head = insert_at_end(head, 20);
   head = insert_at_position(head, 30, 1);
   head = insert_at_position(head, 40, 3);

   // Print the linked list
   print_linked_list(head);

   // Delete a node from the beginning of the linked list
   head = delete_from_beginning(head);

   // Print the linked list
   print_linked_list(head);

   // Delete a node from the end of the linked list
   head = delete_from_end(head);

   // Print the linked list
   print_linked_list(head);

   // Delete a node from a specific position in the linked list
   head = delete_from_position(head, 1);

   // Print the linked list
   print_linked_list(head);

   return 0;
}