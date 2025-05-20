//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
   struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertBegin(struct Node* head, int data) {
   struct Node* newNode = createNode(data);
   newNode->next = head;
   return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertEnd(struct Node* head, int data) {
   struct Node* newNode = createNode(data);
   if (head == NULL) {
      return newNode;
   }
   struct Node* ptr = head;
   while (ptr->next != NULL) {
      ptr = ptr->next;
   }
   ptr->next = newNode;
   return head;
}

// Function to search for a node in the linked list and return its location
int searchNode(struct Node* head, int data) {
   int index = 0;
   struct Node* ptr = head;
   while (ptr != NULL) {
      if (ptr->data == data) {
         return index;
      }
      index++;
      ptr = ptr->next;
   }
   return -1;
}

// Function to delete a node from the linked list
struct Node* deleteNode(struct Node* head, int data) {
   struct Node *prev = NULL, *curr = head;
   while (curr != NULL && curr->data != data) {
      prev = curr;
      curr = curr->next;
   }
   if (curr == NULL) {
      return head;
   }
   if (prev == NULL) {
      head = head->next;
   } 
   else {
      prev->next = curr->next;
   }
   free(curr);
   return head;
}

// Function to view the complete linked list
void viewList(struct Node* head) {
   struct Node* ptr = head;
   printf("\nCurrent Linked List: ");
   while (ptr != NULL) {
      printf("%d -> ", ptr->data);
      ptr = ptr->next;
   }
   printf("NULL");
}

// Main function to execute the linked list operations
int main() {
   struct Node* head = NULL;
   int choice, value, location;
   do {
      printf("\n\nLinked List Operations Menu:");
      printf("\n1. Insert node at the beginning of the linked list");
      printf("\n2. Insert node at the end of the linked list");
      printf("\n3. Find location of a node in the linked list");
      printf("\n4. Delete a node from the linked list");
      printf("\n5. View the complete linked list");
      printf("\n6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1: 
            printf("\nEnter the value to be inserted: ");
            scanf("%d",&value);
            head = insertBegin(head, value);
            break;
         case 2: 
            printf("\nEnter the value to be inserted: ");
            scanf("%d",&value);
            head = insertEnd(head, value);
            break;
         case 3: 
            printf("\nEnter the value to be searched: ");
            scanf("%d",&value);
            location = searchNode(head, value);
            if (location != -1) {
               printf("\nThe node with value %d is located at index %d", value, location);
            }
            else {
               printf("\nThe node with value %d is not present in the linked list", value);
            }
            break;
         case 4: 
            printf("\nEnter the value to be deleted: ");
            scanf("%d",&value);
            head = deleteNode(head, value);
            break;
         case 5: 
            viewList(head);
            break;
         case 6: 
            printf("\nThank you for using the Linked List Operations program!\n");
            exit(0);
         default: 
            printf("\nInvalid choice. Please select a valid option!");
      }
   } while(choice != 6);
   return 0;
}