//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define structure for each node of the linked list
struct Node {
  int data;
  struct Node* next;
};

// Define function to create a new node and return a pointer to it
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Define function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct Node* current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

// Define function to print the linked list
void printList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the linked list
  struct Node* head = NULL;

  // Insert 10 random numbers into the linked list
  for (int i = 0; i < 10; i++) {
    int n = rand() % 100;
    insertAtEnd(&head, n);
  }

  // Print the linked list
  printList(head);
}