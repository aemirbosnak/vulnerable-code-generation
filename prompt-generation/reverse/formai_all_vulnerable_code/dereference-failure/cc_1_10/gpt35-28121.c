//FormAI DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
};

typedef struct node NODE;

NODE* create_node(int data) {
   NODE *newnode;
   newnode = (NODE*)malloc(sizeof(NODE));
   if (newnode == NULL) {
      printf("Memory allocation failed!\n");
      exit(1);
   }
   newnode->data = data;
   newnode->next = NULL;
   return newnode;
}

NODE* add_node(NODE *head, int data) {
   NODE *newnode = create_node(data);
   if (head == NULL)
      head = newnode;
   else {
      NODE *temp = head;
      while(temp->next != NULL)
         temp = temp->next;
      temp->next = newnode;
   }
   return head;
}

NODE* delete_node(NODE *head, int data) {
   NODE *temp=head, *prev;
   if (temp != NULL && temp->data == data) {
      head = temp->next;
      free(temp);
      printf("Element deleted successfully.\n");
      return head;
   }
   while(temp != NULL && temp->data != data) {
      prev = temp;
      temp = temp->next;
   }
   if(temp==NULL) {
      printf("Element not found!\n");
      return head;
   }
   prev->next = temp->next;
   free(temp);
   printf("Element deleted successfully.\n");
   return head;         
}

void display(NODE *head) {
   NODE *temp = head;
   printf("Linked List: ");
   while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main() {
   NODE *head;
   int choice, value;

   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("Welcome to Sherlock's Linked List Operation!\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

   do {
      printf("1. Insert an element\n");
      printf("2. Delete an element\n");
      printf("3. Display the list\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            head = add_node(head, value);
            printf("Element inserted successfully.\n");
            break;
         case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            head = delete_node(head, value);
            break;
         case 3:
            display(head);
            break;
         case 4:
            printf("Goodbye, dear friend!\n");
            exit(0);
         default:
            printf("Invalid choice!\n");
      }
   }while(choice!=4);

   return 0;
}