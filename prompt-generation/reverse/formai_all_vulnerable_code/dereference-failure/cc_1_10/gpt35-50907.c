//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
   int id;
   char name[20];
   float gpa;
};

struct Node {
   struct Student data;
   struct Node *next;
};

void insert(struct Node **head_ref, struct Student new_data) {
   struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}

void delete(struct Node **head_ref, int key) {
   struct Node* temp = *head_ref, *prev;

   if (temp != NULL && temp->data.id == key) {
      *head_ref = temp->next;
      free(temp);
      return;
   }

   while (temp != NULL && temp->data.id != key) {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL) return;

   prev->next = temp->next;
   free(temp);
}

void display(struct Node *node) {
   while (node != NULL) {
      printf("ID: %d \t Name: %s \t GPA: %.2f \n", node->data.id, node->data.name, node->data.gpa);
      node = node->next;
   }
}

int main() {
   struct Node* head = NULL;
   struct Student s1 = {1001, "John", 3.5};
   struct Student s2 = {1002, "Alice", 3.8};
   struct Student s3 = {1003, "Bob", 3.2};

   insert(&head, s1);
   insert(&head, s2);
   insert(&head, s3);

   printf("Initial List \n");
   display(head);

   delete(&head, 1002);

   printf("\nList after deleting 'Alice'\n");
   display(head);

   return 0;
}