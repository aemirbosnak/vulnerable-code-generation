//FormAI DATASET v1.0 Category: Linked list operations ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

// defining the structure of the node
struct node {
   int data;
   struct node *next;
};

// declaring the functions
void insertNode(struct node **, int);
void deleteNode(struct node **, int);
void displayList(struct node *);

int main() {
   struct node *head = NULL;
   int choice, data;
   
   // Displaying the menu of linked list operations
   do {
      printf("----- Linked List Operations -----\n");
      printf("1. Insert a Node\n");
      printf("2. Delete a Node\n");
      printf("3. Display the List\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
         case 2:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
         case 3:
            printf("The List contains: ");
            displayList(head);
            break;
         case 4:
            printf("Exiting...\n");
            exit(0);
            break;
         default:
            printf("Invalid Choice. Please try again.\n");
            break;
      }
   } while(1);

   return 0;
}

// function for inserting a new node
void insertNode(struct node **head, int data) {
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = NULL;
   if (*head == NULL)
      *head = newNode;
   else {
      struct node *temp = *head;
      while(temp->next != NULL)
         temp = temp->next;
      temp->next = newNode;
   }
   printf("%d added to the list.\n", data);
}

// function for deleting a node with specific data
void deleteNode(struct node **head, int data) {
   if (*head == NULL)
      printf("List is empty. Nothing to delete.\n");
   else if ((*head)->data == data) {
      struct node *temp = *head;
      *head = (*head)->next;
      free(temp);
      printf("Node with %d deleted from the list.\n", data);
   }
   else {
      struct node *temp = *head, *prev;
      while (temp != NULL && temp->data != data) {
         prev = temp;
         temp = temp->next;
      }
      if (temp == NULL)
         printf("Node with %d is not found in the list.\n", data);
      else {
         prev->next = temp->next;
         free(temp);
         printf("Node with %d deleted from the list.\n", data);
      }
   }
}

// function for displaying the list
void displayList(struct node *head) {
   if (head == NULL)
      printf("List is empty. Nothing to display.\n");
   else {
      struct node *temp = head;
      while (temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
      }
      printf("\n");
   }
}