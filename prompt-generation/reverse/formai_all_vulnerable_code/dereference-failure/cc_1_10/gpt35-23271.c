//FormAI DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// Function to add a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory for new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // Insert data into new node
  new_node->data = new_data;

  // Set next of the new node to be the current head of linked list
  new_node->next = *head_ref;

  // Set the head of the linked list to be this new node
  *head_ref = new_node;
}

// Function to print all the nodes in the linked list
void printLinkedList(struct Node* node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

// Function to delete a node at a given position in the linked list
void deleteNode(struct Node** head_ref, int position) {
  // If the linked list is empty, return
  if (*head_ref == NULL) {
    return;
  }

  // Store the head node
  struct Node* temp = *head_ref;

  // If the head needs to be removed
  if (position == 0) {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  // Find the previous node of the node to be deleted
  for (int i = 0; temp != NULL && i < position - 1; i++) {
    temp = temp->next;
  }

  // If position is more than number of nodes
  if (temp == NULL || temp->next == NULL) {
    return;
  }

  // Node temp->next is the node to be deleted
  // Store pointer to the next node
  struct Node* next = temp->next->next;

  // Free the node to be deleted
  free(temp->next);

  // Unlink the deleted node from the linked list
  temp->next = next;
}

int main() {
  struct Node* head = NULL;

  // Insert some nodes at beginning of the linked list
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);
  insertAtBeginning(&head, 40);
  insertAtBeginning(&head, 50);

  printf("\nLinked list before deletion: ");
  printLinkedList(head);

  // Delete node at position 2 (third node)
  deleteNode(&head, 2);

  printf("\nLinked list after deletion: ");
  printLinkedList(head);

  return 0;
}