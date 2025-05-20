//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in our linked list
struct Node {
   int data;
   struct Node* next;
};

// Function to add a node to the beginning of a linked list
void insert_beginning(struct Node** head, int new_data) {
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = (*head);
   (*head) = new_node;
}

// Function to print out a linked list
void print_list(struct Node* node) {
   while (node != NULL) {
      printf("%d ", node->data);
      node = node->next;
   }
   printf("\n");
}

// Function to sort a linked list using bubble sort algorithm
void bubble_sort(struct Node** head) {
   int swapped, i;
   struct Node* ptr1;
   struct Node* lptr = NULL;

   if (*head == NULL)
      return;

   do {
      swapped = 0;
      ptr1 = *head;

      while (ptr1->next != lptr) {
         if (ptr1->data > ptr1->next->data) {
            int temp = ptr1->data;
            ptr1->data = ptr1->next->data;
            ptr1->next->data = temp;
            swapped = 1;
         }
         ptr1 = ptr1->next;
      }
      lptr = ptr1;
   } while (swapped);
}

int main() {
   // Create an empty linked list
   struct Node* head = NULL;

   // Add some values to the list
   insert_beginning(&head, 5);
   insert_beginning(&head, 3);
   insert_beginning(&head, 7);
   insert_beginning(&head, 1);

   // Print out the unsorted list
   printf("Unsorted List: ");
   print_list(head);

   // Sort the list using bubble sort
   bubble_sort(&head);

   // Print out the sorted list
   printf("Sorted List: ");
   print_list(head);

   return 0;
}