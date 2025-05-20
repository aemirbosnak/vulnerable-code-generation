//FormAI DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
};
typedef struct node *Node;

void add(Node *head, int n) {
   Node node = (Node) malloc(sizeof(struct node));
   node->data = n;
   node->next = NULL;
   if (*head == NULL) {
      *head = node;
   } else {
      Node temp = *head;
      while (temp->next != NULL) {
         temp = temp->next;
      }
      temp->next = node;
   }
}

void printList(Node head) {
   Node temp = head;
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

void insert(Node *head, int data, int position) {
   Node newNode = (Node) malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = NULL;
   Node prev = NULL, curr = *head;
   int count = 1;
   while (curr != NULL && count != position) {
      prev = curr;
      curr = curr->next;
      count++;
   }
   if (count == position) {
      if (prev == NULL) {
         newNode->next = *head;
         *head = newNode;
      } else {
         newNode->next = curr;
         prev->next = newNode;
      }
   } else {
      printf("Invalid position specified\n");
   }
}

void delete(Node *head, int data) {
   Node prev = NULL, curr = *head;
   while (curr != NULL && curr->data != data) {
      prev = curr;
      curr = curr->next;
   }
   if (curr == NULL) {
      printf("Element not present in the linked list. Cannot delete.\n");
   } else if (prev == NULL) {
      *head = curr->next;
      free(curr);
   } else {
      prev->next = curr->next;
      free(curr);
   }
}

void reverse(Node *head) {
   Node prev = NULL, curr = *head, next = NULL;
   while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }
   *head = prev;
}

void sort(Node *head) {
   Node i = NULL, j = NULL;
   int temp;
   for (i = *head; i != NULL; i = i->next) {
      for (j = i->next; j != NULL; j = j->next) {
         if (i->data > j->data) {
            temp = i->data;
            i->data = j->data;
            j->data = temp;
         }
      }
   }
}

int main() {
   Node head = NULL;
   
   printf("Welcome to the shape shifting Linked List Program!\n");
   printf("Type '1' to add a new element\n");
   printf("Type '2' to insert a new element at a specific position\n");
   printf("Type '3' to delete an element from the list\n");
   printf("Type '4' to reverse the list\n");
   printf("Type '5' to sort the list\n");
   printf("Type '6' to print the list\n");
   printf("Type '0' to exit the program\n\n");
   
   int choice, data, position;
   while (1) {
       printf("Enter your choice: ");
       scanf("%d", &choice);
       switch (choice) {
          case 0:
             printf("Exiting program...");
             return 0;
          case 1:
             printf("Enter the data: ");
             scanf("%d", &data);
             add(&head, data);
             printf("Element %d added successfully!\n", data);
             break;
          case 2:
             printf("Enter the data: ");
             scanf("%d", &data);
             printf("Enter the position: ");
             scanf("%d", &position);
             insert(&head, data, position);
             break;
          case 3:
             printf("Enter the data to be deleted: ");
             scanf("%d", &data);
             delete(&head, data);
             break;
          case 4:
             printf("Reversing the list...\n");
             reverse(&head);
             printf("List reversed!\n");
             break;
          case 5:
             printf("Sorting the list...\n");
             sort(&head);
             printf("List sorted!\n");
             break;
          case 6:
             printf("Printing the list...\n");
             printList(head);
             break;
          default:
             printf("Invalid choice! Please try again.\n");
       }
   }
   
   return 0;
}