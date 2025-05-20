//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node* next;
} node;

void print_list(node* head) {
   while (head) {
      printf("%d ", head->data);
      head = head->next;
   }
   printf("\n");
}

node* insert_at_end(node* head, int data) {
   node* newNode = (node*)malloc(sizeof(node));
   newNode->data = data;
   newNode->next = NULL;
   if (head) {
      node* temp = head;
      while (temp->next) {
         temp = temp->next;
      }
      temp->next = newNode;
   }
   else {
      head = newNode;
   }
   return head;
}

node* delete_node(node* head, int data) {
   if (head->data == data) {
      node* temp = head->next;
      free(head);
      return temp;
   }
   node* prev = head;
   node* current = head->next;
   while (current) {
      if (current->data == data) {
         prev->next = current->next;
         free(current);
         return head;
      }
      prev = current;
      current = current->next;
   }
   return head;
}

node* reverse_list(node* head) {
   node* prev = NULL;
   node* current = head;
   while (current) {
      node* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }
   return prev;
}

int main()
{
   node* head = NULL;
   head = insert_at_end(head, 10);
   head = insert_at_end(head, 20);
   head = insert_at_end(head, 30);
   head = insert_at_end(head, 40);
   head = insert_at_end(head, 50);

   printf("List: ");
   print_list(head);

   printf("Deleting 30 from list...\n");
   head = delete_node(head, 30);
   printf("List: ");
   print_list(head);

   printf("Reversing List...\n");
   head = reverse_list(head);
   printf("List: ");
   print_list(head);

   return 0;
}