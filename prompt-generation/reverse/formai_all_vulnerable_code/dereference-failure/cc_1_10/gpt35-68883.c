//FormAI DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to insert a new node at the beginning
void insertAtBeginning(struct node **head, int data) {
   struct node *newNode = createNode(data);
   newNode->next = *head;
   *head = newNode;
   printf("%d inserted at beginning!\n", data);
}

// Function to insert a new node at the end
void insertAtEnd(struct node **head, int data) {
   struct node *newNode = createNode(data);
   struct node *temp = *head;
   while(temp->next != NULL)
      temp = temp->next;
   temp->next = newNode;
   printf("%d inserted at end!\n", data);
}

// Function to insert a new node at a particular position
void insertAtPosition(struct node **head, int data, int position) {
   struct node *newNode = createNode(data);
   if(*head == NULL) {
      *head = newNode;
      return;
   }
   struct node *temp = *head;
   if(position == 1) {
      newNode->next = *head;
      *head = newNode;
      printf("%d inserted at position %d!\n", data, position);
      return;
   }
   while(position-- > 2 && temp->next != NULL)
      temp = temp->next;
   newNode->next = temp->next;
   temp->next = newNode;
   printf("%d inserted at position %d!\n", data, position);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct node **head) {
   if(*head == NULL) {
      printf("Cannot delete from empty list!\n");
      return;
   }
   struct node *temp = *head;
   *head = (*head)->next;
   free(temp);
   printf("First element deleted!\n");
}

// Function to delete a node from the end
void deleteFromEnd(struct node **head) {
   if(*head == NULL) {
      printf("Cannot delete from empty list!\n");
      return;
   }
   struct node *temp = *head;
   while(temp->next->next != NULL)
      temp = temp->next;
   struct node *temp2 = temp->next;
   temp->next = NULL;
   free(temp2);
   printf("Last element deleted!\n");
}

// Function to delete a node from a particular position
void deleteFromPosition(struct node **head, int position) {
   if(*head == NULL) {
      printf("Cannot delete from empty list!\n");
      return;
   }
   struct node *temp = *head, *temp2;
   if(position == 1) {
      *head = (*head)->next;
      free(temp);
      printf("Element deleted at position %d!\n", position);
      return;
   }
   while(position-- > 2 && temp->next != NULL)
      temp = temp->next;
   if(temp->next == NULL) {
      printf("Position does not exist!\n");
      return;
   }
   temp2 = temp->next;
   temp->next = temp2->next;
   free(temp2);
   printf("Element deleted at position %d!\n", position);
}

// Function to display the list
void displayList(struct node **head) {
   if(*head == NULL) {
      printf("The list is empty!\n");
      return;
   }
   printf("The list is: ");
   struct node *temp = *head;
   while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
}

int main() {
   struct node *head = NULL;
   int choice, data, position;
   while(1) {
      printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display the list\n0. Exit\nEnter choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("Enter data to be inserted at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
         case 2:
            printf("Enter data to be inserted at end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
         case 3:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
         case 4:
            deleteFromBeginning(&head);
            break;
         case 5:
            deleteFromEnd(&head);
            break;
         case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteFromPosition(&head, position);
            break;
         case 7:
            displayList(&head);
            break;
         case 0:
            exit(0);
            break;
         default:
            printf("Invalid choice!\n");
            break;
      }
   }
   return 0;
}