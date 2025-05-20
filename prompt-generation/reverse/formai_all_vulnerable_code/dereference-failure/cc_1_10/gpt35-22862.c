//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct Node { // defining Node structure
  int data; // data to be stored
  struct Node *next; // pointer to the next element
};

void add_to_list(struct Node **head, int data) { // function to add element to list
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // allocating memory for new node
  new_node->data = data; // assigning data to the new node
  new_node->next = (*head); // pointing new node to the current head
  (*head) = new_node; // making the new node as the new head
}

void print_list(struct Node *node) { // function to print the list
  while (node != NULL) {
    printf("%d ", node->data); // printing the data of the current node
    node = node->next; // moving to the next node
  }
}

void delete_from_list(struct Node **head, int key) { // function to delete an element from the list by value
  struct Node *temp = *head, *prev;
  
  if (temp != NULL && temp->data == key) { // if the first element is to be deleted
    *head = temp->next; // changing the head of the list to the next element
    free(temp); // deallocating the memory of the deleted node
    return;
  }
  
  while (temp != NULL && temp->data != key) { // finding the node with the value to be deleted
    prev = temp;
    temp = temp->next;
  }
  
  if (temp == NULL) return; // if the value is not found
  
  prev->next = temp->next; // skipping the value to be deleted
  free(temp); // deallocating the memory of the deleted node
}

int main() {
  struct Node *head = NULL; // Initializing an empty linked list
  
  add_to_list(&head, 5); // Adding elements to the list
  add_to_list(&head, 2);
  add_to_list(&head, 9);
  add_to_list(&head, 1);
  add_to_list(&head, 3);
  
  printf("Original Linked List: ");
  print_list(head); // Printing the original linked list
  
  delete_from_list(&head, 2); // Deleting an element from the list by value
  printf("\nLinked List after Deletion: ");
  print_list(head); // Printing the linked list after deletion
  
  return 0;
}