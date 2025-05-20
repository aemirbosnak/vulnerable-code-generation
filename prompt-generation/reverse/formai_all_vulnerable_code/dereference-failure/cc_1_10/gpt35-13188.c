//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

// defining a new data type struct node
struct node {
   int data;
   struct node *next;
};

// function to create a new node
struct node* createNode(int data) {
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// function to insert a new node at the beginning of a singly linked list
void insertAtBeginning(struct node **head, int data) {
   struct node *newNode = createNode(data);
   newNode->next = *head;
   *head = newNode;
}

// function to delete a node from beginning of a singly linked list
void deleteFromBeginning(struct node **head) {
   if(*head == NULL) {
      printf("List is empty!!!\n");
      return;
   }
   struct node *temp = *head;
   *head = (*head)->next;
   free(temp);
}

// function to display the elements of a singly linked list
void display(struct node *head) {
   if(head == NULL) {
      printf("List is empty!!!\n");
      return;
   }
   struct node *temp = head;
   while(temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}

// main function
int main() {
   struct node *head = NULL; // initializing the head of the singly linked list to NULL
   int choice, ele;
   do {
      printf("\n-------------------------------------\n");
      printf("\n\tMENU\n1. Insert an element\n2. Delete an element\n3. Display the list\n4. Exit\n");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &ele);
            insertAtBeginning(&head, ele);
            printf("%d is inserted!\n", ele);
            break;
         case 2:
            deleteFromBeginning(&head);
            break;
         case 3:
            display(head);
            break;
         case 4:
            printf("\nExiting...\n");
            exit(0);
            break;
         default:
            printf("\nInvalid Choice!!!\n");
      }
   } while(choice != 4);
   return 0;
}