//FormAI DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

typedef struct node Node;

Node* createLinkedList(int arr[], int size) {
  Node* head = (Node*)malloc(sizeof(Node));
  head->data = arr[0];
  head->next = NULL;

  Node* current = head;

  for(int i = 1; i < size; i++) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = arr[i];
    new_node->next = NULL;

    current->next = new_node;
    current = new_node;
  }

  return head;
}

void insertAtBeginning(Node** head, int data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = *head;

  *head = new_node;
}

void insertAtEnd(Node* head, int data) {
  while(head->next != NULL) {
    head = head->next;
  }

  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  head->next = new_node;
}

void insertAtPosition(Node* head, int data, int position) {

  for(int i = 1; i < position; i++) {
    head = head->next;
  }

  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = head->next;

  head->next = new_node;
}

void deleteAtBeginning(Node** head) {
  Node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteAtEnd(Node* head) {
  while(head->next->next != NULL) {
    head = head->next;
  }

  Node* temp = head->next;
  head->next = NULL;
  free(temp);
}

void deleteAtPosition(Node* head, int position) {
  for(int i = 1; i < position; i++) {
    head = head->next;
  }

  Node* temp = head->next;
  head->next = temp->next;
  free(temp);
}

void printList(Node* head) {
  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }

  printf("\n");
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr)/sizeof(arr[0]);

  Node* head = createLinkedList(arr, size);

  printf("Original List: ");
  printList(head);

  insertAtBeginning(&head, 0);
  printf("List after inserting 0 at the beginning: ");
  printList(head);

  insertAtEnd(head, 6);
  printf("List after inserting 6 at the end: ");
  printList(head);

  insertAtPosition(head, 10, 3);
  printf("List after inserting 10 at position 3: ");
  printList(head);

  deleteAtBeginning(&head);
  printf("List after deleting first element: ");
  printList(head);

  deleteAtEnd(head);
  printf("List after deleting last element: ");
  printList(head);

  deleteAtPosition(head, 3);
  printf("List after deleting element at position 3: ");
  printList(head);

  return 0;
}