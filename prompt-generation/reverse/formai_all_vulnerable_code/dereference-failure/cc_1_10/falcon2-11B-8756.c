//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new node at the beginning
struct Node* insertAtBeginning(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
  return *head;
}

// Function to insert a new node at the end
struct Node* insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  struct Node* temp = *head;
  while (temp->next!= NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return *head;
}

// Function to delete a node
struct Node* deleteNode(struct Node** head, int key) {
  struct Node* temp = *head;
  struct Node* prev = NULL;
  if (temp!= NULL && temp->data == key) {
    *head = temp->next;
    free(temp);
    return *head;
  }
  while (temp->next!= NULL && temp->next->data!= key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp->next == NULL) {
    return *head;
  }
  prev->next = temp->next;
  free(temp);
  return *head;
}

// Function to display a linked list
void displayList(struct Node* head) {
  struct Node* temp = head;
  while (temp!= NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Driver code
int main() {
  struct Node* head = NULL;
  insertAtBeginning(&head, 10);
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);
  displayList(head);
  deleteNode(&head, 20);
  displayList(head);
  return 0;
}