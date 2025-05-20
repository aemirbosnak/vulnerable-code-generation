//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *create_node(int data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(struct Node **head, int data) {
  struct Node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(struct Node **head, int data) {
  struct Node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  struct Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

// Function to insert a node after a given node
void insert_after_node(struct Node **head, int data, int after_data) {
  struct Node *new_node = create_node(data);
  struct Node *temp = *head;
  while (temp != NULL) {
    if (temp->data == after_data) {
      new_node->next = temp->next;
      temp->next = new_node;
      return;
    }
    temp = temp->next;
  }
  printf("Node with data %d not found in the linked list.\n", after_data);
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(struct Node **head) {
  if (*head == NULL) {
    printf("The linked list is empty.\n");
    return;
  }
  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(struct Node **head) {
  if (*head == NULL) {
    printf("The linked list is empty.\n");
    return;
  }
  struct Node *temp = *head;
  if (temp->next == NULL) {
    *head = NULL;
    free(temp);
    return;
  }
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

// Function to delete a node from the middle of the linked list
void delete_from_middle(struct Node **head, int data) {
  struct Node *temp = *head;
  struct Node *prev = NULL;
  while (temp != NULL) {
    if (temp->data == data) {
      if (prev == NULL) {
        *head = (*head)->next;
      } else {
        prev->next = temp->next;
      }
      free(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  printf("Node with data %d not found in the linked list.\n", data);
}

// Function to print the linked list
void print_linked_list(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  struct Node *head = NULL;

  // Inserting nodes into the linked list
  insert_at_beginning(&head, 10);
  insert_at_beginning(&head, 20);
  insert_at_beginning(&head, 30);
  insert_at_end(&head, 40);
  insert_after_node(&head, 50, 30);

  // Printing the linked list
  printf("The linked list is: ");
  print_linked_list(head);

  // Deleting nodes from the linked list
  delete_from_beginning(&head);
  delete_from_end(&head);
  delete_from_middle(&head, 50);

  // Printing the linked list
  printf("The linked list after deletions is: ");
  print_linked_list(head);

  return 0;
}