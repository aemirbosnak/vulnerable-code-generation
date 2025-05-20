//FormAI DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
 
struct node {
   int data;
   struct node *next;
};
 
struct node *head = NULL;
 
void displayList() {
   struct node *temp;
   temp = head;
   printf("\n[ ");
   
   while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
   }
   
   printf("]\n");
}
 
void insertAtBeginning(int data) {
   struct node *newNode;
   newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = head;
   head = newNode;
   printf("\nNode inserted at the beginning!\n");
}
 
void insertAtEnd(int data) {
   struct node *newNode, *temp;
   newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = NULL;
   
   if(head == NULL) {
      head = newNode;
      printf("\nNode inserted at the end!\n");
      return;
   }
   
   temp = head;
   
   while(temp->next != NULL)
      temp = temp->next;
   
   temp->next = newNode;
   printf("\nNode inserted at the end!\n");
}
 
void insertAtN(int data, int position) {
   struct node *newNode, *temp;
   int i;
   newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = data;
   
   if(position == 1) {
      newNode->next = head;
      head = newNode;
      printf("\nNode inserted at position %d\n",position);
      return;
   }
   
   temp = head;
   
   for(i=1;i<position-1;i++) {
      if(temp->next == NULL) {
         printf("\nThere are less than %d elements in the list!\n",position);
         return;
      }
      
      temp = temp->next;
   }
   
   newNode->next = temp->next;
   temp->next = newNode;
   printf("\nNode inserted at position %d\n",position);
}
 
void deleteFromBeginning() {
   struct node *temp;
   
   if(head == NULL) {
      printf("\nThe list is empty!\n");
      return;
   }
   
   temp = head;
   head = head->next;
   free(temp);
   printf("\nNode deleted from the beginning!\n");
}
 
void deleteFromEnd() {
   struct node *prevNode, *curNode;
   
   if(head == NULL) {
      printf("\nThe list is empty!\n");
      return;
   }
   
   if(head->next == NULL) {
      head = NULL;
      free(head);
      printf("\nOnly node of the list deleted!\n");
      return;
   }
   
   prevNode = head;
   curNode = head->next;
   
   while(curNode->next != NULL) {
      prevNode = curNode;
      curNode = curNode->next;
   }
   
   prevNode->next = NULL;
   free(curNode);
   printf("\nNode deleted from the end!\n");
}
 
void deleteFromN(int position) {
   struct node *prevNode, *curNode;
   int i;
   
   if(head == NULL) {
      printf("\nThe list is empty!\n");
      return;
   }
   
   curNode = head;
   
   for(i=1;i<position;i++) {
      if(curNode->next == NULL) {
         printf("\nThere are less than %d elements in the list!\n",position);
         return;
      }
      
      prevNode = curNode;
      curNode = curNode->next;
   }
   
   prevNode->next = curNode->next;
   free(curNode);
   printf("\nNode deleted from position %d\n",position);
}
 
void update(int data, int position) {
   struct node *temp;
   int i;
   
   if(head == NULL) {
      printf("\nThe list is empty!\n");
      return;
   }
   
   temp = head;
   
   for(i=1;i<position;i++) {
      if(temp->next == NULL) {
         printf("\nThere are less than %d elements in the list!\n",position);
         return;
      }
      
      temp = temp->next;
   }
   
   temp->data = data;
   printf("\nNode updated at position %d\n",position);
}
 
int main() {
   int choice, data, position;
   
   while(1) {
      printf("Linked List Operations\n");
      printf("1. Insert at beginning\n");
      printf("2. Insert at end\n");
      printf("3. Insert at position\n");
      printf("4. Delete from beginning\n");
      printf("5. Delete from end\n");
      printf("6. Delete from position\n");
      printf("7. Update a node\n");
      printf("8. Display the list\n");
      printf("9. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      
      switch(choice) {
         case 1:
            printf("\nEnter the element to be inserted at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
            
         case 2:
            printf("\nEnter the element to be inserted at end: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
            
         case 3:
            printf("\nEnter the element to be inserted at position: ");
            scanf("%d", &data);
            printf("\nEnter the position where the element to be inserted: ");
            scanf("%d", &position);
            insertAtN(data, position);
            break;
            
         case 4:
            deleteFromBeginning();
            break;
            
         case 5:
            deleteFromEnd();
            break;
            
         case 6:
            printf("\nEnter the position at which the node to be deleted: ");
            scanf("%d", &position);
            deleteFromN(position);
            break;
            
         case 7:
            printf("\nEnter the new data value of the node: ");
            scanf("%d", &data);
            printf("\nEnter the position you want to update: ");
            scanf("%d", &position);
            update(data, position);
            break;
            
         case 8:
            displayList();
            break;
            
         case 9:
            exit(0);
            break;
            
         default:
            printf("\nWrong choice!\n");
      }
   }
   
   return 0;
}