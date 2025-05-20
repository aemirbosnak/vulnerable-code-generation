//FormAI DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

typedef struct node node_t;

void add_to_list(node_t **head, int data) {
   node_t *new_node = malloc(sizeof(node_t));

   new_node->data = data;
   new_node->next = *head;
   *head = new_node;
}

void print_list(node_t *head) {
   node_t *current = head;

   while (current != NULL) {
      printf("%d\n", current->data);
      current = current->next;
   }
}

void delete_list(node_t **head) {
   node_t *current = *head;
   node_t *next;

   while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
   }

   *head = NULL;
}

int main() {
   node_t *head = NULL;

   add_to_list(&head, 4);
   add_to_list(&head, 5);
   add_to_list(&head, 6);
   add_to_list(&head, 7);

   print_list(head);

   delete_list(&head);

   return 0;
}