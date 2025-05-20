//FormAI DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the linked list
struct Node {
  int data;
  struct Node *next;
};

// Function to print the linked list
void printLinkedList(struct Node *head) {
  printf("Linked List: ");
  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  // Creating an empty linked list
  struct Node *head = NULL;

  // Adding nodes to the linked list
  int n, num;
  printf("Enter number of nodes: ");
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    printf("Enter data for node %d: ", i+1);
    scanf("%d", &num);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    if(head == NULL)
      head = newNode;
    else {
      struct Node *traverse = head;
      while(traverse->next != NULL)
        traverse = traverse->next;
      traverse->next = newNode;
    }
    printLinkedList(head); // Print the linked list after adding each node
  }

  // Deleting a node from the linked list
  int pos;
  printf("Enter the position of the node to delete: ");
  scanf("%d", &pos);
  if(head == NULL) {
    printf("Linked List is empty.\n");
    return 0;
  }
  if(pos == 1) {
    head = head->next;
    free(head);
    printLinkedList(head);
    return 0;
  }
  struct Node *traverse = head;
  for(int i = 1; i < pos-1; i++) {
    traverse = traverse->next;
    if(traverse == NULL) {
      printf("Invalid position.\n");
      return 0;
    }
  }
  struct Node *temp;
  temp = traverse->next;
  traverse->next = temp->next;
  free(temp);
  printLinkedList(head);

  // Reversing the linked list
  struct Node *prev = NULL, *current = head, *next = NULL;
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  printLinkedList(head);

  // Finding the middle element of the linked list
  struct Node *slow = head, *fast = head;
  while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  printf("Middle element: %d\n", slow->data);

  return 0;
}