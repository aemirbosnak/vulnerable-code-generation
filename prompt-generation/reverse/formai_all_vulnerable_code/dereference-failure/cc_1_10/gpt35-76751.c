//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct node {
 int data;           //Data element
 struct node *next;  //Pointer to next node
};

//Function to insert node at the beginning of linked list
void insertAtBeginning(struct node **head_ref, int new_data) {
 struct node *new_node = (struct node *) malloc(sizeof(struct node));
 new_node->data = new_data;
 new_node->next = (*head_ref);
 (*head_ref) = new_node;
}

//Function to insert node at the end of linked list
void insertAtEnd(struct node **head_ref, int new_data) {
 struct node *new_node = (struct node *) malloc(sizeof(struct node));
 struct node *last = (*head_ref);
 new_node->data = new_data;
 new_node->next = NULL;
 if (*head_ref == NULL) {
   *head_ref = new_node;
   return;
 }
 while (last->next != NULL)
   last = last->next;
 last->next = new_node;
 return;
}

//Function to delete node from linked list
void deleteNode(struct node **head_ref, int key) {
 struct node *temp = *head_ref, *prev;
 if (temp != NULL && temp->data == key) {
   *head_ref = temp->next;
   free(temp);
   return;
 }
 while (temp != NULL && temp->data != key) {
   prev = temp;
   temp = temp->next;
 }
 if (temp == NULL)
   return;
 prev->next = temp->next;
 free(temp);
}

//Function to traverse linked list and print data elements
void traverseList(struct node *n) {
 while (n != NULL) {
   printf("%d ", n->data);
   n = n->next;
 }
}

//Driver function to test above functions
int main() {
 struct node* head = NULL;
 printf("1. Insert at beginning\n");
 printf("2. Insert at end\n");
 printf("3. Delete a node\n");
 printf("4. Traverse list\n");
 printf("5. Exit\n");
 int choice, elem, key;
 do {
   printf("\nEnter choice: ");
   scanf("%d", &choice);
   switch (choice) {
     case 1:
         printf("Enter element to insert: ");
         scanf("%d", &elem);
         insertAtBeginning(&head, elem);
         break;
     case 2:
         printf("Enter element to insert: ");
         scanf("%d", &elem);
         insertAtEnd(&head, elem);
         break;
     case 3:
         printf("Enter element to delete: ");
         scanf("%d", &key);
         deleteNode(&head, key);
         break;
     case 4:
         printf("Linked list: ");
         traverseList(head);
         break;
     case 5:
         exit(0);
         break;
     default:
         printf("Invalid choice.\n");
   }
 } while (choice != 5);
 return 0;
}